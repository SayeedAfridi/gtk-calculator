#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "signal_process.c"


int main(int argc, char * argv[]){
    gtk_init (&argc, &argv);
    builder = gtk_builder_new ();
    if (gtk_builder_add_from_file (builder, "/opt/gtk-calculator/design/calcDesign.glade", &error) == 0)
    {
        g_printerr ("Error loading file: %s\n", error->message);
        g_clear_error (&error);
        return 1;
    }
    
    window = gtk_builder_get_object (builder, "window");
    gtk_window_set_icon(GTK_WINDOW(window), create_pixbuf("/opt/gtk-calculator/design/icon.png"));
    g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);
    zero = gtk_builder_get_object (builder, "zero");
    one = gtk_builder_get_object (builder, "one");
    two = gtk_builder_get_object (builder, "two");
    three = gtk_builder_get_object (builder, "three");
    four = gtk_builder_get_object (builder, "four");
    five = gtk_builder_get_object (builder, "five");
    six = gtk_builder_get_object (builder, "six");
    seven = gtk_builder_get_object (builder, "seven");
    eight = gtk_builder_get_object (builder, "eight");
    nine = gtk_builder_get_object (builder, "nine");
    plus = gtk_builder_get_object (builder, "plus");
    minus = gtk_builder_get_object (builder, "minus");
    mul = gtk_builder_get_object (builder, "mul");
    divide = gtk_builder_get_object (builder, "divide");
    AC = gtk_builder_get_object (builder, "AC");
    dot = gtk_builder_get_object (builder, "dot");
    entry = gtk_builder_get_object (builder, "entry");
    calc = gtk_builder_get_object (builder, "calc");
    
    addSignal();

    gtk_entry_set_alignment (GTK_ENTRY(entry), 1);
	gtk_main();
}

