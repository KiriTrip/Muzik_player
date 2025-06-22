#include <stdio.h>
#include <gtk/gtk.h>

static void app_activate(GApplication *app, gpointer *user_data)
{
    GtkWidget *window = gtk_application_window_new(GTK_APPLICATION (app));
    gtk_window_set_title(GTK_WINDOW (window) ,"Muzik Player");
    gtk_window_set_default_size(GTK_WINDOW (window), 525, 700);
    gtk_window_present(GTK_WINDOW (window));
}

int main(int argc, char **argv)
{
    GtkApplication *app = gtk_application_new("com.muzik.Player", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(app_activate) ,NULL);
    int status = g_application_run(G_APPLICATION (app), argc, argv);
    g_object_unref(app);

    return status;
}