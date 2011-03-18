#include <gtk/gtk.h>
#include "cheese-flash.h"

static void
button_clicked (GtkButton *button,
		CheeseFlash *flash)
{
	cheese_flash_fire (flash);
}

int main (int argc, char **argv)
{
	GtkWidget *window, *button;
	CheeseFlash *flash;

	gtk_init (&argc, &argv);

	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	flash = cheese_flash_new (window);
	button = gtk_button_new_with_label ("Fire flash");
	g_signal_connect (G_OBJECT (button), "clicked",
			  G_CALLBACK (button_clicked), flash);
	gtk_container_add (GTK_CONTAINER (window), button);
	gtk_widget_show_all (window);

	gtk_main ();

	return 0;
}
