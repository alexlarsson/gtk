/* GDK - The GIMP Drawing Kit
 *
 * gdkglcontext.h: GL context abstraction
 * 
 * Copyright © 2014  Emmanuele Bassi
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __GDK_GL_CONTEXT_H__
#define __GDK_GL_CONTEXT_H__

#if !defined (__GDK_H_INSIDE__) && !defined (GDK_COMPILATION)
#error "Only <gdk/gdk.h> can be included directly."
#endif

#include <gdk/gdkversionmacros.h>
#include <gdk/gdktypes.h>

G_BEGIN_DECLS

#define GDK_TYPE_GL_CONTEXT             (gdk_gl_context_get_type ())
#define GDK_GL_CONTEXT(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), GDK_TYPE_GL_CONTEXT, GdkGLContext))
#define GDK_IS_GL_CONTEXT(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GDK_TYPE_GL_CONTEXT))

GDK_AVAILABLE_IN_3_14
GType gdk_gl_context_get_type (void) G_GNUC_CONST;

GDK_AVAILABLE_IN_3_14
GdkDisplay *            gdk_gl_context_get_display      (GdkGLContext *context);

GDK_AVAILABLE_IN_3_14
GdkGLPixelFormat *      gdk_gl_context_get_pixel_format (GdkGLContext *context);

GDK_AVAILABLE_IN_3_14
void                    gdk_gl_context_clear_window     (GdkGLContext *context);
GDK_AVAILABLE_IN_3_14
void                    gdk_gl_context_flush_buffer     (GdkGLContext *context);
GDK_AVAILABLE_IN_3_14
gboolean                gdk_gl_context_make_current     (GdkGLContext *context);
GDK_AVAILABLE_IN_3_14
void                    gdk_gl_context_set_window       (GdkGLContext *context,
                                                         GdkWindow    *window);
GDK_AVAILABLE_IN_3_14
GdkWindow *             gdk_gl_context_get_window       (GdkGLContext *context);
GDK_AVAILABLE_IN_3_14
void                    gdk_gl_context_update           (GdkGLContext *context);

GDK_AVAILABLE_IN_3_14
void                    gdk_gl_context_clear_current    (void);
GDK_AVAILABLE_IN_3_14
GdkGLContext *          gdk_gl_context_get_current      (void);

G_END_DECLS

#endif /* __GDK_GL_CONTEXT_H__ */
