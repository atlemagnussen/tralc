#include <gtk/gtk.h>
#include <cairo.h>
#include "../config.h"

static void do_drawing(cairo_t *);

static void tran_setup(GtkWidget *win)
{
    GdkScreen *screen;
    GdkVisual *visual;

    gtk_widget_set_app_paintable(win, TRUE);
    screen = gdk_screen_get_default();
    visual = gdk_screen_get_rgba_visual(screen);

    if (visual != NULL && gdk_screen_is_composited(screen)) {
        gtk_widget_set_visual(win, visual);
    }
}

static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data)
{
    do_drawing(cr);

    return FALSE;
}

static void do_drawing(cairo_t *cr)
{
    cairo_set_source_rgba(cr, 0, 0, 0, 0.6);
    cairo_set_operator(cr, CAIRO_OPERATOR_SOURCE);
    cairo_paint(cr);
}

static void print_hello (GtkWidget *widget, gpointer data)
{
    g_print ("Quitted %s version %s\n", PROJECT_NAME, PROJECT_VERSION);
}

static void activate (GtkApplication *app, gpointer user_data)
{
    GtkWidget *window;
    GtkWidget *darea;
    GtkWidget *box1;
    GtkWidget *label;
    GtkWidget *button;
    GtkWidget *button_box;

    window = gtk_application_window_new (app);
    tran_setup(window);
    gtk_window_set_title (GTK_WINDOW (window), "Window");
    gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);

    box1 = gtk_box_new (FALSE, 0);
    gtk_container_add (GTK_CONTAINER (window), box1);
    gtk_widget_show (box1);

    char version[] = "Version ";
    char label_text[14];
    label_text[0]='\0';

    strncat (label_text, version, 8);
    strncat(label_text, PROJECT_VERSION, 13);
    label = gtk_label_new(label_text);
    gtk_box_pack_start (GTK_BOX (box1), label, TRUE, TRUE, 0);
    gtk_widget_show (label);

    button_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
    gtk_container_add (GTK_CONTAINER (box1), button_box);

    button = gtk_button_new_with_label ("Quit");
    g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
    g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);
    gtk_container_add (GTK_CONTAINER (button_box), button);

    gtk_widget_show_all (window);
}

int main (int argc, char **argv)
{
    GtkApplication *app;
    int status;

    app = gtk_application_new ("it.magnussen.tralc", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;
}
