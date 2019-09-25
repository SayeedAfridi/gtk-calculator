#include <gtk/gtk.h>

#include "../includes/calculator.h"

GdkPixbuf *create_pixbuf(const gchar *filename)
{
	GdkPixbuf *pixbuf;
	GError *error = NULL;
	pixbuf = gdk_pixbuf_new_from_file(filename, &error);
	if (!pixbuf)
	{
		fprintf(stderr, "%s\n", error->message);
		g_error_free(error);
	}
	return pixbuf;
}


void addSignal() {
    g_signal_connect(zero, "clicked", G_CALLBACK(input), NULL);
    g_signal_connect(one, "clicked", G_CALLBACK(input), NULL);
    g_signal_connect(two, "clicked", G_CALLBACK(input), NULL);
    g_signal_connect(three, "clicked", G_CALLBACK(input), NULL);
    g_signal_connect(four, "clicked", G_CALLBACK(input), NULL);
    g_signal_connect(five, "clicked", G_CALLBACK(input), NULL);
    g_signal_connect(six, "clicked", G_CALLBACK(input), NULL);
    g_signal_connect(seven, "clicked", G_CALLBACK(input), NULL);
    g_signal_connect(eight, "clicked", G_CALLBACK(input), NULL);
    g_signal_connect(nine, "clicked", G_CALLBACK(input), NULL);
    g_signal_connect(plus, "clicked", G_CALLBACK(calculate), NULL);
    g_signal_connect(minus, "clicked", G_CALLBACK(calculate), NULL);
    g_signal_connect(divide, "clicked", G_CALLBACK(calculate), NULL);
    g_signal_connect(mul, "clicked", G_CALLBACK(calculate), NULL);
    g_signal_connect(dot, "clicked", G_CALLBACK(input), NULL);
    g_signal_connect(AC, "clicked", G_CALLBACK(clear), NULL);
    g_signal_connect(calc, "clicked", G_CALLBACK(equal), NULL);
}



void calculate(GtkWidget *widget, gpointer data){
    const gchar *text = gtk_button_get_label(GTK_BUTTON(widget));
    sign[0] = text[0];
    double y = atof(gtk_entry_get_text(GTK_ENTRY(entry)));
    int show = 0;
    if(s1 == 0){
        s1 += y;
    }else if(sign[0] == '+'){
        s1 += y;
        show = 1;
    }else if(sign[0] == '-'){
        s1 -= y;
        show = 1;
    }else if(sign[0] == '*'){
        s1 *= y;
        show = 1;
    }else if(sign[0] == '/'){
        s1 /= y;
        show = 1;
    }
    char s[20];
    sprintf( s, "%.3f", s1);

    if(show == 1){
        gtk_entry_set_text(GTK_ENTRY(entry), s);
    }else{
        gtk_entry_set_text(GTK_ENTRY(entry), "0");
    }
}

void input(GtkWidget *widget, gpointer data)
{

	const gchar *entry_text = gtk_entry_get_text(GTK_ENTRY(entry));
	gint pos = strlen(entry_text);
	gtk_editable_insert_text(GTK_EDITABLE(entry),
			gtk_button_get_label(GTK_BUTTON(widget)), -1, &pos);
}

void clear(GtkWidget *widget, gpointer data)
{

	gtk_entry_set_text(GTK_ENTRY(entry), "0");
    s1 = 0;
}

void equal(GtkWidget *widget, gpointer data){
    double y = atof(gtk_entry_get_text(GTK_ENTRY(entry)));
    if(sign[0] == '+'){
        s1 += y;
    }else if(sign[0] == '-'){
        s1 -= y;
    }else if(sign[0] == '*'){
        s1 *= y;
    }else if(sign[0] == '/'){
        s1 /= y;
    }
    char s[20];
    sprintf( s, "%.3f", s1);
    gtk_entry_set_text(GTK_ENTRY(entry), s);
}
