#include<gtk/gtk.h>
#include<iostream>

static void button_clicked(GtkWidget* widget,gpointer data)
{
	g_print("button is clicked\n");

}

int main(int argc,char** argv)
{
	gtk_init(&argc,&argv);
	GtkWidget* window,*label,*button;
	label=gtk_label_new("SERIES GENERATOR!");
	//button=gtk_button_new_with_label("start!");
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(window), "SERIES GENERATOR!");
	gtk_window_set_default_size(GTK_WINDOW(window), 900, 600);
	
	g_signal_connect(window,"delete-event",G_CALLBACK(gtk_main_quit),NULL);
	//g_signal_connect(button,"clicked",G_CALLBACK(button_clicked),NULL);
	
	//gtk_container_add(GTK_CONTAINER(window),label);
	//gtk_container_add(GTK_CONTAINER(window),button);
	gtk_widget_show_all(window);
	gtk_main();
		
return 0;
}
