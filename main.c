#include <gtk/gtk.h>

// https://www.gtk.org/docs/getting-started/hello-world/

static void
print_hello (GtkWidget *widget,
             gpointer   data)
{
  g_print ("Hello World\n");
}

static void
activate (GtkApplication *app,
          gpointer        user_data)
{
  GtkWidget *window;
  GtkWidget *button;
  
  GtkWidget *grid   = gtk_grid_new();
  gtk_grid_set_column_spacing(GTK_GRID(grid),10);
  gtk_grid_set_row_spacing(GTK_GRID(grid), 6);

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);

  button = gtk_button_new_with_label ("Hello World");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
  ///gtk_window_set_child (GTK_WINDOW (window), button);

  gtk_grid_attach(GTK_GRID(grid), button, 0, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), gtk_button_new_with_label ("Hello World #2"), 1, 1, 1, 1);

  gtk_window_set_child (GTK_WINDOW (window), grid); //gtk_button_new_with_label ("Hello World #2"));

  gtk_window_present (GTK_WINDOW (window));
}

int
main (int    argc,
      char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
