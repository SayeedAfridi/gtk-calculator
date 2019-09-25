#include <math.h>

#include <gtk/gtk.h>

#ifndef CALCULATOR_H
#define CALCULATOR_H

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


#endif
