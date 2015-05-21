#ifndef VE_IMPL_GLX_H
#define VE_IMPL_GLX_H

/** misc
    vei_glx is a multithreaded implementation of the VE OpenGL renderer
    using the GLX X extension for processing OpenGL commands.
    <p>Functions in this module that are not implementations of another
    API should only be called sparingly by applications, as they are not
    portable to other OpenGL-based implementations of VE.  Applications
    which include the <code>vei_glx.h</code> header file do not need to
    include the <code>vei_gl.h</code> header file or other OpenGL
    header files.  These are included automatically.
    <p>This module implements functions from the <code>ve_render.h</code>
    and <code>vei_gl.h</code> modules.
*/

#include <vei_gl.h>
#include <GL/glx.h>

#ifdef __cplusplus
extern "C" {
#endif
#if 0
}
#endif

/** struct VeiGlxWindow
    Represents the GLX window.  There is one VeiGlxWindow structure for
    each open VeWindow object.
*/
typedef struct vei_glx_window {
  /** member dpy
      The X display on which this window is located.
  */
  Display *dpy;
  /** member pipe
      All displays used by the renderer are enumerated at run-time.
      The pipe value is the enumeration of the Display represented
      by the <code>dpy</code> member.  This field allows for quick
      and easy comparisons of displays (i.e. if two windows share
      the same display even if the windows have separate connections
      to the display).
  */
  int pipe;
  /** member win
      The X window which the render is using for this window.
  */
  Window win;
  /** member ctx
      The GLX context which this window is rendered with.  Each window
      has its own GLX context.
  */
  GLXContext ctx;
  /** member stereo
      A boolean value - if non-zero, then this window is stereo.
  */
  int stereo;
  /** member x,y,w,h
      A cached copy of the window's geometry.  It is assumed in the
      current model that the geometry does not change once the window
      has been opened.
  */
  int x,y,w,h;
  /** member ext_swap_group
      If non-zero then it has been detected that the display upon which
      this window is located supports the <code>SGIX_swap_group</code> 
      extension.  If detected, the system will attempt to take advantage
      of this extension.
  */
  int ext_swap_group;
} VeiGlxWindow;

/** function veiGlxSetVisualAttr
    Adds the given terminated list of GLX attributes to the set of
    attributes to use when opening windows.  These attributes will apply
    to all windows that are opened.  These attributes must be set after
    the call to <code>veRenderInit()</code> but before the call to 
    <code>veRenderRun</code>.

    @param attr
    An array of attributes, the last of which must be <code>None</code>.
    See the manual page for <code>glXChooseVisual()</code> for details
    on known attributes.
*/
void veiGlxSetVisualAttr(int *attr); /* adds GLX visual attributes to apply
				    when opening windows */

#ifdef __cplusplus
}
#endif

#endif /* VE_IMPL_GLX_H */
