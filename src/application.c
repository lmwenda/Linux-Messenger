#include <stdio.h> 
#include <gtk/gtk.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "../include/application.h"
#include "../include/client.h"
#include "../include/server.h"

#define PORT 8080

static int counter = 0;

void send_message( GtkWidget *widget, gpointer   data ) 
{ 
   // printf equivalent in GTK+
   
   g_print ("Welcome to Linux Messenger\n");
   g_print ("Your message has sent...");


};

void print_textmessage(GtkWidget *widget, gpointer data) // basically send message func
{
   printf("...");
};

void destroy( GtkWidget *widget,gpointer   data )
{
   gtk_main_quit ();
};

int main( int argc,char *argv[] )
{

   GtkWidget *window;

   gtk_init (&argc, &argv);
 
   window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
   gtk_window_set_title(GTK_WINDOW(window), "Arch Messenger");

   g_signal_connect (window, "destroy",
   G_CALLBACK (destroy), NULL);
   gtk_container_set_border_width
      (GTK_CONTAINER (window), 10);


   // element intialiaziation

   GtkWidget *b_send;
   GtkWidget *e_message = gtk_entry_new();
   gtk_entry_set_text(GTK_ENTRY(e_message), "Hey!!!");
   b_send = gtk_button_new_with_label ("Message");

   // signals and handling

   g_signal_connect(GTK_BUTTON(b_send),
      "clicked",G_CALLBACK (send_message),
      "button");

   g_signal_connect(GTK_ENTRY(e_message),
      "activate", G_CALLBACK(print_textmessage),
      NULL);
 
   // boxes
   
   GtkWidget *chatbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
   GtkWidget *inputsbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
   GtkWidget *main_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);

   // size of widgets

   gtk_widget_set_size_request(e_message, 800, 10); // set width to 100 pixels
   gtk_widget_set_size_request(b_send, 100, 10); // set width to 100 pixels

   // adding elements to a box

   gtk_box_pack_start(GTK_BOX(inputsbox), e_message, TRUE, TRUE, 10);
   gtk_box_pack_start(GTK_BOX(inputsbox), b_send, TRUE, TRUE, 10);

   // adding to container 
   
   gtk_container_add(GTK_CONTAINER (main_box), chatbox);
   gtk_container_add (GTK_CONTAINER (main_box), inputsbox);
   gtk_container_add (GTK_CONTAINER (window), main_box);

   // creating two threads
   
   pthread_t thrs, thrc;
   pthread_create(&thrs, NULL, ths_func, NULL); // thread for server 
   pthread_create(&thrc, NULL, thc_func, NULL); // thread for client

   gtk_widget_show_all(window); 

   gtk_main ();

   return 0;
};
