#pragma once
#include <gtk/gtk.h>

// void* ths_func(void* arg); server
// void* thc_func(void* arg); client
void send_message(GtkWidget *widget, gpointer data);
void print_textmessage(GtkWidget *widget, gpointer data);
int main(int arg1, char *arg2[]);
void destroy( GtkWidget *widget,gpointer   data );

