/*
 * Compile me with:
 *  Steps
 *
 *  1. $apt-get install libgtk-2.0-dev libbluetooth-dev
 *
 *   gcc -o tut tut.c $(pkg-config --cflags --libs gtk+-2.0 gmodule-2.0)
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <gtk-2.0/gtk/gtk.h>

GtkWidget           *win_Main;
GtkWidget           *scl_List;
GtkWidget           *tbl_Main;

GtkTreeIter         iter;
GtkListStore        *store = NULL;
GtkWidget           *treeview = NULL;
GtkCellRenderer     *renderer = NULL;
GtkTreeStore *model;

GtkWidget           *btn_key_Add;
GtkTreeViewColumn   *col;

//---------------------------------------------------------
// AddTreeEntry
//---------------------------------------------------------
void AddTreeEntry()
{
/*
GtkTreeModel *model;
GtkTreeIter  iter;

    model = gtk_tree_view_get_model (GTK_TREE_VIEW (treeview));
    gtk_tree_store_append (GTK_TREE_STORE (model), &iter, NULL);
    gtk_tree_store_set (GTK_TREE_STORE (model), &iter,
                          COL_ONE, "John",
                          COL_TWO, "Doe",
                          -1);
    return;*/
}


int
main( int argc, char **argv ){

    GtkBuilder *builder;
    GtkWidget  *window;
    GtkButton  *button;
    GError     *error = NULL;

    /* Init GTK+ */
    gtk_init( &argc, &argv );
//
    /* Create new GtkBuilder object */
    builder = gtk_builder_new();
    /* Load UI from file. If error occurs, report it and quit application.
     * Replace "tut.glade" with your saved project. */
    if( ! gtk_builder_add_from_file( builder, "triploS.glade", &error ) )
    {
        g_warning( "%s", error->message );
        g_free( error );
        return( 1 );
    }

    /* Get main window pointer from UI */
    window = GTK_WIDGET( gtk_builder_get_object( builder, "window1" ) );

    button = GTK_WIDGET( gtk_builder_get_object( builder, "button1" ) );

    //store = GTK_WIDGET( gtk_builder_get_object( builder, "liststore1" ) );


    /* Connect signals */
    gtk_builder_connect_signals( builder, NULL );

    g_signal_connect(button,"clicked",G_CALLBACK(printf("Apertou o butao")),NULL);

    /* Destroy builder, since we don't need it anymore */
    g_object_unref( G_OBJECT( builder ) );

    /* Show window. All other widgets are automatically shown by GtkBuilder */
    gtk_widget_show( window );

    /* Start main loop */
    gtk_main();

    return( 0 );
}
