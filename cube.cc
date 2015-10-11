#include <glib.h>

#include <gdk/gdkx.h>
#include <epoxy/glx.h>
#include <epoxy/gl.h>
#include <gtk/gtk.h>

//fool compile into thinking a variable is using. prevents warnings
#define IGNORE_VAR(type, identifier)            \
  {                                             \
    type IGNORED_VARIABLE_abcd = identifier;    \
    identifier = IGNORED_VARIABLE_abcd;         \
  }

const GLchar *vert_src ="\n" \
  "#version 330                                  \n" \
  "#extension GL_ARB_explicit_attrib_location: enable  \n" \
  "                                              \n" \
  "layout(location = 0) in vec2 in_position;     \n" \
  "                                              \n" \
  "void main()                                   \n" \
  "{                                             \n" \
  "  gl_Position = vec4(in_position, 0.0, 1.0);  \n" \
  "}                                             \n";

const GLchar *frag_src ="\n" \
  "void main (void)                              \n" \
  "{                                             \n" \
  "  gl_FragColor = vec4(1.0, 0.5, 1.0, 1.0);    \n" \
  "}                                             \n";

GLuint gl_vao, gl_buffer, gl_program;

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

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.0, 0.0, 0.0, 1.0);

  glUseProgram(gl_program);
  glBindVertexArray(gl_vao);
  glDrawArrays(GL_TRIANGLES, 0, 3);

  glBindVertexArray (0);
  glUseProgram (0);

  glFlush();

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

  GLfloat verts[] = 
    {
      +0.0f, +1.0f,
      -1.0f, -1.0f,
      +1.0f, -1.0f,
    };

  GLuint frag_shader, vert_shader;
  frag_shader = glCreateShader(GL_FRAGMENT_SHADER);
  vert_shader = glCreateShader(GL_VERTEX_SHADER);

  glShaderSource(frag_shader, 1, &frag_src, NULL);
  glShaderSource(vert_shader, 1, &vert_src, NULL);

  glCompileShader(frag_shader);
  glCompileShader(vert_shader);

  gl_program = glCreateProgram();
  glAttachShader(gl_program, frag_shader);
  glAttachShader(gl_program, vert_shader);
  glLinkProgram(gl_program);

  glGenVertexArrays(1, &gl_vao);
  glBindVertexArray(gl_vao);

  glGenBuffers(1, &gl_buffer);
  glBindBuffer(GL_ARRAY_BUFFER, gl_buffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
  glBindVertexArray(0);

  glDeleteBuffers(1, &gl_buffer);

  return true;
}

static void unrealize (GtkWidget *widget,
                       gpointer   user_data) {

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
