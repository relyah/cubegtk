#include <glib.h>

#include <gdk/gdkx.h>
#include <epoxy/glx.h>
#include <epoxy/gl.h>
#include <gtk/gtk.h>

#include "OpenGLApplication.h"

//fool compile into thinking a variable is using. prevents warnings
#define IGNORE_VAR(type, identifier)            \
  {                                             \
    type IGNORED_VARIABLE_abcd = identifier;    \
    identifier = IGNORED_VARIABLE_abcd;         \
  }

OpenGLApplication *app;

static void on_window_closed (GtkWidget *widget, gpointer data)
{
  gtk_main_quit ();
}

/*static GdkGLContext* create_context (GtkGLArea *area,
  gpointer   user_data) {

  }*/

static void resize (GtkGLArea *area,
                    gint       width,
                    gint       height,
                    gpointer   user_data) { 
}

static gboolean render(GtkGLArea *area, GdkGLContext *context)
{
  IGNORE_VAR(GdkGLContext*, context);
  IGNORE_VAR(GtkGLArea*, area);

  app->Render();

  return true;
}

static gboolean realize(GtkGLArea *area, GdkGLContext *context)
{
  IGNORE_VAR(GdkGLContext*, context);

  gtk_gl_area_make_current(GTK_GL_AREA(area));
  if (gtk_gl_area_get_error (GTK_GL_AREA(area)) != NULL)
  {
    printf("Failed to initialiize buffers\n");
    return FALSE;
  }

  int width = gtk_widget_get_allocated_width((GtkWidget*)area);
  int height = gtk_widget_get_allocated_height((GtkWidget*)area);
  app = new OpenGLApplication(width,height);
  app->Init();

  return true;
}

static void unrealize (GtkWidget *widget,
                       gpointer   user_data) {
  app->Shutdown();
  delete app;
}


static void connection_mapper (GtkBuilder *builder, GObject *object,
                               const gchar *signal_name, const gchar *handler_name,
                               GObject *connect_object, GConnectFlags flags, gpointer user_data)
{
  g_print ("Verbinde %s mit %s\n", signal_name, handler_name);

  if (g_strcmp0(handler_name, "gtk_main_quit")==0) {
    g_signal_connect(object,signal_name,G_CALLBACK(on_window_closed),0);
    //} else if (g_strcmp0(handler_name, "create_context")==0) {
    //g_signal_connect(object,signal_name,G_CALLBACK(create_context),user_data);
  } else if (g_strcmp0(handler_name, "render")==0) {
    g_signal_connect(object,signal_name,G_CALLBACK(render),0);
  } else if (g_strcmp0(handler_name, "resize")==0) {
    g_signal_connect(object,signal_name,G_CALLBACK(resize),user_data);
  } else if (g_strcmp0(handler_name, "realize")==0) {
    g_signal_connect(object,signal_name,G_CALLBACK(realize),0);
  } else if (g_strcmp0(handler_name, "unrealize")==0) {
    g_signal_connect(object,signal_name,G_CALLBACK(unrealize),user_data);
  } else {
    g_print ("unbekannte Callback %s %s\n",handler_name, signal_name);
  }
}


int main (int argc, char *argv[])
{

  GtkBuilder *builder;
  GError *errors = NULL;
  GtkWidget *window;

  gtk_init (&argc, &argv);
  builder = gtk_builder_new ();
  gtk_builder_add_from_file (builder, "interface.ui.xml", &errors);
  //gtk_builder_connect_signals (builder, builder);
  gtk_builder_connect_signals_full (builder, connection_mapper, NULL);
  window = GTK_WIDGET(gtk_builder_get_object (builder, "CubeVisor"));
  gtk_widget_show_all (window);
  gtk_main ();
  return 0;
}
