/* 
 * Application: Terminal
 * Script     : dragdrop.c
 * Author     : Fuat Bölük
 * Creation   : 01 Aralık 2017
 * Contact    : <fuat@fuxproject.org>
 * Copyright  : Fux Project
 * License    : GPLv3+
 *
 */


/* Drag Defines */
enum { TARGET_STRING };
static GtkTargetEntry target_list[] = {
     { "STRING",        0, TARGET_STRING },
     { "text/plain",    0, TARGET_STRING }
};


/* Drag Drop */
static gboolean on_drag_drop(GtkWidget *terminal, GdkDragContext *context, gint x, gint y, guint time, gpointer user_data)
{
    gboolean valid;
    GdkAtom target;

    valid = TRUE;

    if (gdk_drag_context_list_targets(context))
    {
        target = GDK_POINTER_TO_ATOM(gdk_drag_context_list_targets(context));
        gtk_drag_get_data(terminal, context, target, time);
    }
    else
    {
        valid = FALSE;
    }
    return valid;
}


/* Drag Data Received */
static gboolean on_drag_data_received(GtkWidget *terminal, GdkDragContext *context, int x, int y,
                                      GtkSelectionData *selection_data, guint info, guint time)
{
    char *data, *uris;
    char url[1000];
    gboolean success = FALSE;
    gboolean success_data = FALSE;

    if((selection_data != NULL) && (gtk_selection_data_get_length(selection_data) > 0))
    {

        if (gdk_drag_context_get_suggested_action(context) == GDK_ACTION_COPY)
        {
            success_data = TRUE;
        }

        if (gdk_drag_context_get_suggested_action(context) == GDK_ACTION_MOVE)
        {
            success_data = TRUE;
        }

        if (gdk_drag_context_get_suggested_action(context) == GDK_ACTION_LINK)
        {
            success_data = TRUE;
        }

        switch (info)
        {
            case TARGET_STRING:
                data = (char *) gtk_selection_data_get_text(selection_data);
                uris = strtok(data, "\n");

                while ((uris != NULL) && (gtk_selection_data_get_length(data) > 0))
                {
                    sprintf(url, " %s", uris + 7);
                    utf8_decode(url, url);
                    vte_terminal_feed_child(VTE_TERMINAL(terminal), url, strlen(url) - 1);
                    uris = strtok(NULL, "\n");
                }
                
                success = TRUE;
                break;

            default:
                return FALSE;
        }
    }
    gtk_drag_finish(context, success, success_data, time);
}
