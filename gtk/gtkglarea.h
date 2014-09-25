/* GTK - The GIMP Toolkit
 *
 * gtkglarea.h: A GL drawing area
 *
 * Copyright © 2014  Emmanuele Bassi
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __GTK_GL_AREA_H__
#define __GTK_GL_AREA_H__

#if !defined (__GTK_H_INSIDE__) && !defined (GTK_COMPILATION)
#error "Only <gtk/gtk.h> can be included directly."
#endif

#include <gtk/gtkwidget.h>

G_BEGIN_DECLS

#define GTK_TYPE_GL_AREA                (gtk_gl_area_get_type ())
#define GTK_GL_AREA(obj)                (G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_TYPE_GL_AREA, GtkGLArea))
#define GTK_IS_GL_AREA(obj)             (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_TYPE_GL_AREA))
#define GTK_GL_AREA_CLASS(klass)        (G_TYPE_CHECK_CLASS_CAST ((klass), GTK_TYPE_GL_AREA, GtkGLAreaClass))
#define GTK_IS_GL_AREA_CLASS(klass)     (G_TYPE_CHECK_CLASS_TYPE ((klass), GTK_TYPE_GL_AREA))
#define GTK_GL_AREA_GET_CLASS(obj)      (G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_TYPE_GL_AREA, GtkGLAreaClass))

typedef struct _GtkGLArea               GtkGLArea;
typedef struct _GtkGLAreaClass          GtkGLAreaClass;

/**
 * GtkGLArea:
 *
 * A #GtkWidget used for drawing with OpenGL.
 *
 * Since: 3.14
 */
struct _GtkGLArea
{
  /*< private >*/
  GtkWidget parent_instance;
};

/**
 * GtkGLAreaClass:
 * @create_context: class closure for the #GtkGLArea::create-context signal
 * @render: class closure for the #GtkGLArea::render signal
 *
 * The `GtkGLAreaClass` structure contains only private data.
 *
 * Since: 3.14
 */
struct _GtkGLAreaClass
{
  /*< private >*/
  GtkWidgetClass parent_class;

  /*< public >*/
  GdkGLContext * (* create_context) (GtkGLArea        *area,
                                     GdkGLPixelFormat *format);

  gboolean       (* render)         (GtkGLArea        *area,
                                     GdkGLContext     *context);

  /*< private >*/
  gpointer _padding[6];
};

GDK_AVAILABLE_IN_3_14
GType gtk_gl_area_get_type (void) G_GNUC_CONST;

GDK_AVAILABLE_IN_3_14
GtkWidget *     gtk_gl_area_new                 (GdkGLPixelFormat *format);

GDK_AVAILABLE_IN_3_14
GdkGLContext *  gtk_gl_area_get_context         (GtkGLArea        *area);

GDK_AVAILABLE_IN_3_14
gboolean        gtk_gl_area_make_current        (GtkGLArea        *area);
GDK_AVAILABLE_IN_3_14
void            gtk_gl_area_flush_buffer        (GtkGLArea        *area);

G_END_DECLS

#endif /* __GTK_GL_AREA_H__ */
