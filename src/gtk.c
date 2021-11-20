#include <gtk/gtk.h>

void css() //Load css in gtk
{
    GtkCssProvider *provider;
    GdkDisplay *display;
    GdkScreen *screen;

    provider = gtk_css_provider_new ();
    display = gdk_display_get_default ();
    screen = gdk_display_get_default_screen (display);
    gtk_style_context_add_provider_for_screen (screen, GTK_STYLE_PROVIDER (provider), 
            GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    const gchar *myCssFile = "/opt/battery_alert/glade/style.css";
    GError *error = 0;

    gtk_css_provider_load_from_file(provider, g_file_new_for_path(myCssFile), &error);
    g_object_unref (provider);
}


int showAlert() {
    GtkWidget *window;

    gtk_init(NULL, NULL);

    // Constructs a GtkBuilder instance.
    GtkBuilder* builder = gtk_builder_new();

    // Loads the UI description.
    GError* error = NULL;
    if (gtk_builder_add_from_file(builder, "/opt/battery_alert/glade/battery.glade", &error) == 0)
    {
        g_printerr("Error loading file: %s\n", error->message);
        g_clear_error(&error);
        return 1;
    }

    css();

    window = GTK_WIDGET(gtk_builder_get_object (builder, "window"));

    //Floating window 
    gtk_window_set_type_hint((GtkWindow*)window, GDK_WINDOW_TYPE_HINT_DIALOG);

    //Window size
    gtk_window_set_default_size(GTK_WINDOW(window), 640, 480);
    gtk_window_set_resizable (GTK_WINDOW(window), FALSE);


    g_signal_connect(G_OBJECT (window), "destroy", (GCallback)gtk_main_quit, NULL);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

