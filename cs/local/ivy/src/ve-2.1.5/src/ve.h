#ifndef VE_H
#define VE_H

/** misc
    This header file is the one that should generally be used by applications.
    It does not define anything itself, but includes all of the header files
    from the various modules of the core VE library.
*/

#define VE_MAJOR_REVISION 2
#define VE_MINOR_REVISION 1

/* this is the header file that clients should include */
/* after this, they will need the implementation header */
#include <ve_clock.h>
#include <ve_core.h>
#include <ve_debug.h>
#include <ve_device.h>
#include <ve_driver.h>
#include <ve_env.h>
#include <ve_error.h>
#include <ve_keysym.h>
#include <ve_main.h>
#include <ve_math.h>
#include <ve_render.h>
#include <ve_stats.h>
#include <ve_thread.h>
#include <ve_timer.h>
#include <ve_util.h>
#include <ve_mp.h>
#include <ve_profiler.h>

#endif /* VE_H */
