/* 
 * Application: Terminal
 * Script     : shortcuts.c
 * Author     : Fuat Bölük
 * Creation   : 01 Aralık 2017
 * Contact    : <fuat@fuxproject.org>
 * Copyright  : Fux Project
 * License    : GPLv3+
 *
 */


/* Key Press */
static gboolean on_key_press(GtkWidget *terminal, GdkEventKey *event, gpointer user_data)
{
    switch (event->keyval)
    {
      case GDK_KEY_c:
      case GDK_KEY_C:
        if (event->state & GDK_CONTROL_MASK){
            if (event->state & GDK_SHIFT_MASK){
                vte_terminal_copy_clipboard(VTE_TERMINAL(terminal));
                return TRUE;
            }
            return FALSE; 
        }
        break;
      case GDK_KEY_v:
      case GDK_KEY_V:
        if (event->state & GDK_CONTROL_MASK){
            if (event->state & GDK_SHIFT_MASK){
                vte_terminal_paste_clipboard(VTE_TERMINAL(terminal));
                return TRUE;
            }
            return FALSE; 
        }
        break;
      case GDK_KEY_e:
      case GDK_KEY_E:
        if (event->state & GDK_CONTROL_MASK){
            if (event->state & GDK_SHIFT_MASK){
                char cmd[1000];
                strcpy(cmd, " clear \n");
                vte_terminal_feed_child(VTE_TERMINAL(terminal), cmd, strlen(cmd));
                return TRUE;
            }
            return FALSE; 
        }
        break;
      case GDK_KEY_h:
      case GDK_KEY_H:
        if (event->state & GDK_CONTROL_MASK){
            if (event->state & GDK_SHIFT_MASK){
                char cmd[1000];
                strcpy(cmd, " history \n");
                vte_terminal_feed_child(VTE_TERMINAL(terminal), cmd, strlen(cmd));
                return TRUE;
            }
            return FALSE; 
        }
        break;
      case GDK_KEY_t:
      case GDK_KEY_T:
        if (event->state & GDK_CONTROL_MASK){
            if (event->state & GDK_SHIFT_MASK){
                char cmd[1000];
                strcpy(cmd, "terminal & disown");
                system(cmd);
                return TRUE;
            }
            return FALSE; 
        }
        break;
      case GDK_KEY_q:
      case GDK_KEY_Q:
        if (event->state & GDK_CONTROL_MASK){
            if (event->state & GDK_SHIFT_MASK){
                char cmd[1000];
                strcpy(cmd, " exit && exit \n");
                vte_terminal_feed_child(VTE_TERMINAL(terminal), cmd, strlen(cmd));
                return TRUE;
            }
            return FALSE; 
        }
        break;
      default:
        return FALSE; 
    }
    return FALSE; 
}
