/* 
 * Application: Terminal
 * Script     : terminal.c
 * Author     : Fuat Bölük
 * Creation   : 01 Aralık 2017
 * Contact    : <fuat@fuxproject.org>
 * Copyright  : Fux Project
 * License    : GPLv3+
 *
 */

#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <vte/vte.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include <gdk/gdkkeysyms.h>
#include <glib/gi18n.h>
#include <gio/gio.h>
#include <glib.h>

#include "helper.c"
#include "shortcuts.c"
#include "dragdrop.c"
#include "functions.c"
#include "popupmenu.c"


/* Change Title */
static gboolean on_title_changed(GtkWidget *terminal, gpointer user_data)
{
    GtkWindow *window = user_data;
    gtk_window_set_title(window, vte_terminal_get_window_title(VTE_TERMINAL(terminal)));
    return TRUE;
}


/* Main Function */
int main(int argc, char *argv[])
{
    GtkWidget *window, *terminal;
    GdkRGBA back_rgba = { 0, 0, 0, 0.9 };
    GdkRGBA front_rgba = { 1, 1, 1, 1.0 };
    PangoFontDescription *font = NULL;
    GdkVisual *visual; 

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 765, 360);
    gtk_window_set_title(GTK_WINDOW(window), "Terminal");
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_NONE);
    gtk_window_set_icon_name(GTK_WINDOW(window), "utilities-terminal");

    gtk_widget_set_app_paintable(GTK_WINDOW(window), TRUE);

    visual = gdk_screen_get_rgba_visual(gtk_widget_get_screen(window));
    gtk_widget_set_visual(GTK_WINDOW(window), visual);

    terminal = vte_terminal_new();
    vte_terminal_set_color_background(VTE_TERMINAL(terminal), &back_rgba);
    vte_terminal_set_color_foreground(VTE_TERMINAL(terminal), &front_rgba);

    font = pango_font_description_from_string("Monospace Regular 11");
    vte_terminal_set_font(VTE_TERMINAL(terminal), font);

    gchar **envp = g_get_environ();
    gchar **command = (gchar *[]){g_strdup(g_environ_getenv(envp, "SHELL")), NULL };
    g_strfreev(envp);

    vte_terminal_spawn_sync(VTE_TERMINAL(terminal),
        VTE_PTY_DEFAULT,
        NULL,       /* working directory */
        command,    /* command           */
        NULL,       /* environment       */
        0,          /* spawn flags       */
        NULL, NULL, /* child setup       */
        NULL,       /* child pid         */
        NULL, NULL);

    vte_terminal_set_scrollback_lines(VTE_TERMINAL(terminal), -1);
    vte_terminal_set_scroll_on_output(VTE_TERMINAL(terminal), TRUE);
    vte_terminal_set_scroll_on_keystroke(VTE_TERMINAL(terminal), TRUE);
    vte_terminal_set_rewrap_on_resize(VTE_TERMINAL(terminal), TRUE);
    vte_terminal_set_mouse_autohide(VTE_TERMINAL(terminal), TRUE);

    g_signal_connect(window, "delete-event", gtk_main_quit, NULL);

    gtk_drag_dest_set(terminal, GTK_DEST_DEFAULT_ALL, target_list, 3, GDK_ACTION_COPY | GDK_ACTION_MOVE | GDK_ACTION_LINK);

    g_signal_connect(terminal, "drag_drop", G_CALLBACK(on_drag_drop), GTK_WINDOW(window));
    g_signal_connect(terminal, "drag_data_received", G_CALLBACK(on_drag_data_received), GTK_WINDOW(window));

    g_signal_connect(terminal, "child-exited", gtk_main_quit, NULL);
    g_signal_connect(terminal, "window-title-changed", G_CALLBACK(on_title_changed), GTK_WINDOW(window));
    g_signal_connect(terminal, "key_press_event", G_CALLBACK(on_key_press), GTK_WINDOW(window));

    g_signal_connect(terminal, "button-press-event", G_CALLBACK(terminal_right_click), NULL);

    gtk_container_add(GTK_CONTAINER(window), terminal);
    gtk_widget_show_all(terminal);

    gtk_widget_set_size_request(window, 765, 360);
    gtk_widget_show_all(window);

    gtk_main();
}
