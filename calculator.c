#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

GObject* window;
GObject * zero;
GObject *one;
GObject *two;
GObject *three;
GObject *four;
GObject *five;
GObject *six;
GObject *seven;
GObject *eight;
GObject *nine;
GObject *plus;
GObject *minus;
GObject *divide;
GObject *mul;
GObject *AC;
GObject *dot;
GObject *calc;
GObject * entry;
GtkBuilder * builder;
GError *error = NULL;

double s1 = 0;
char sign[1];
char res[100];

void calculate(GtkWidget *widget, gpointer data);
void equal(GtkWidget *widget, gpointer data);

void input(GtkWidget *widget, gpointer data);
void clear(GtkWidget *widget, gpointer data);

int main(int argc, char * argv[]){
    gtk_init (&argc, &argv);
    builder = gtk_builder_new ();
    if (gtk_builder_add_from_file (builder, "calcDesign.glade", &error) == 0)
    {
        g_printerr ("Error loading file: %s\n", error->message);
        g_clear_error (&error);
        return 1;
    }
    
    window = gtk_builder_get_object (builder, "window");
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


    gtk_entry_set_alignment (GTK_ENTRY(entry), 1);
	gtk_main();
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