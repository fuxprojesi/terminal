/* 
 * Application: Terminal
 * Script     : popupmenu.c
 * Author     : Fuat Bölük
 * Creation   : 01 Aralık 2017
 * Contact    : <fuat@fuxproject.org>
 * Copyright  : Fux Project
 * License    : GPLv3+
 *
 */


/* Right Click */
static gboolean terminal_right_click(GtkWidget *terminal, GdkEventButton *event, gpointer userdata)
{
    if (event->type == GDK_BUTTON_PRESS  &&  event->button == 3)
    {
        GtkWidget *menu, *sep1, *sep2, *sep3, *termitem, *termicon;
        GtkWidget *copyitem, *copyicon, *pasteitem, *pasteicon;
        GtkWidget *cleanitem, *cleanicon, *histitem, *histicon;
        GtkWidget *quititem, *quiticon;

        menu = gtk_menu_new();

        termitem = gtk_image_menu_item_new_with_label("Terminal Aç");
        termicon = gtk_image_new_from_icon_name("utilities-terminal-symbolic", GTK_ICON_SIZE_MENU);
        gtk_image_menu_item_set_image(termitem, termicon);
        gtk_image_menu_item_set_always_show_image(termitem, TRUE);
        g_signal_connect_swapped(termitem, "activate", (GCallback) open, terminal);

        copyitem = gtk_image_menu_item_new_with_label("Kopyala");
        copyicon = gtk_image_new_from_icon_name("edit-copy-symbolic", GTK_ICON_SIZE_MENU);
        gtk_image_menu_item_set_image(copyitem, copyicon);
        gtk_image_menu_item_set_always_show_image(copyitem, TRUE);
        g_signal_connect_swapped(copyitem, "activate", (GCallback) copy, terminal);

        pasteitem = gtk_image_menu_item_new_with_label("Yapıştır");
        pasteicon = gtk_image_new_from_icon_name("edit-paste-symbolic", GTK_ICON_SIZE_MENU);
        gtk_image_menu_item_set_image(pasteitem, pasteicon);
        gtk_image_menu_item_set_always_show_image(pasteitem, TRUE);
        g_signal_connect_swapped(pasteitem, "activate", (GCallback) paste, terminal);

        cleanitem = gtk_image_menu_item_new_with_label("Ekranı Temizle");
        cleanicon = gtk_image_new_from_icon_name("edit-clear-all-symbolic", GTK_ICON_SIZE_MENU);
        gtk_image_menu_item_set_image(cleanitem, cleanicon);
        gtk_image_menu_item_set_always_show_image(cleanitem, TRUE);
        g_signal_connect_swapped(cleanitem, "activate", (GCallback) clear, terminal);

        histitem = gtk_image_menu_item_new_with_label("Komut Geçmişi");
        histicon = gtk_image_new_from_icon_name("document-open-recent-symbolic", GTK_ICON_SIZE_MENU);
        gtk_image_menu_item_set_image(histitem, histicon);
        gtk_image_menu_item_set_always_show_image(histitem, TRUE);
        g_signal_connect_swapped(histitem, "activate", (GCallback) history, terminal);

        quititem = gtk_image_menu_item_new_with_label("Terminali Kapat");
        quiticon = gtk_image_new_from_icon_name("window-close-symbolic", GTK_ICON_SIZE_MENU);
        gtk_image_menu_item_set_image(quititem, quiticon);
        gtk_image_menu_item_set_always_show_image(quititem, TRUE);
        g_signal_connect(quititem, "activate", (GCallback) gtk_main_quit, terminal);

        sep1 = gtk_separator_menu_item_new();
        sep2 = gtk_separator_menu_item_new();
        sep3 = gtk_separator_menu_item_new();

        gtk_menu_shell_append(GTK_MENU_SHELL(menu), termitem);
        gtk_menu_shell_append(GTK_MENU_SHELL(menu), sep1);
        gtk_menu_shell_append(GTK_MENU_SHELL(menu), copyitem);
        gtk_menu_shell_append(GTK_MENU_SHELL(menu), pasteitem);
        gtk_menu_shell_append(GTK_MENU_SHELL(menu), sep2);
        gtk_menu_shell_append(GTK_MENU_SHELL(menu), cleanitem);
        gtk_menu_shell_append(GTK_MENU_SHELL(menu), histitem);
        gtk_menu_shell_append(GTK_MENU_SHELL(menu), sep3);
        gtk_menu_shell_append(GTK_MENU_SHELL(menu), quititem);

        gtk_widget_show_all(menu);

        gtk_menu_popup(GTK_MENU(menu), NULL, NULL, NULL, NULL, (event != NULL) ? event->button : 0, gdk_event_get_time((GdkEvent*)event));
    }
    return FALSE;
}
