#ifndef VE_PROFILER_H
#define VE_PROFILER_H

#include <ve_clock.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
#if 0
}
#endif

/** misc
    <p>
    The ve_profiler module provides a simple "profiling" mechanism for
    VE.  The profiling mechanism allows timestamped internal VE events
    to be written to a log for both debugging and performance 
    analysis.  These events must be deliberately generated by modules
    in VE by calling <code>vePfEvent()</code>.  All functions in this
    module begin with <code>vePf</code>.  This prefix should not be
    used in any other VE module.</p>
    <p>By default, recording of profiling events is turned off.  Recording
    can be controlled by code using the <code>vePfDest()</code>,
    <code>vePfRecord()</code>, and <code>vePfStop()</code> function calls.
    If the <code>VE_PF</code> environment variable is set, then its value
    is used as an argument to <code>vePfDest()</code> at startup and
    recording is enabled by default.</p>
    <p>Modules that want to temporarily disable profiling in certain
    sections of code should use the <code>vePfPause()</code> and 
    <code>vePfResume()</code> function calls.</p>
*/

/** function vePfInit
    <p>Initializes the profiler.  Typically called by <code>veInit()</code>.
    Most applications should not need to call this function.</p>
    <p>If the profiler fails to initialize (e.g. bad value in an environment
    variable) then a warning will be raised but execution will continue.
    A failure in the profiler will generally not halt a VE program.</p>
*/
void vePfInit(void);

/** vePfDest
    <p>Specifies the destination for profiling events.  If no destination
    is specified then the default is for events to be written to stderr.
    Any argument beginning with "@" is treated as special.
    The following special strings are recognized:
    <ul>
    <li><code>@stdout</code> - write events to stdout.</li>
    <li><code>@stderr</code> - write events to stderr.</li>
    <li><code>@none</code> - silently ignore all events.</li>
    </ul>
    If the argument does not begin with "@" then it is treated as a filename
    to which profiling events should be written.
    </p>
    <p>Only one profiling event destination can be active at one time.
    Any call to this function flushes any previously reported events and
    causes the old destination to be closed before the new one is opened.
    If the argument is a file, then the file will be created if necessary
    and truncated if it already exists.</p>

    @param dest
    The destination to which to write events.  If this is <code>NULL</code>
    then this is equivalent to an argument of "@none".  If this parameter
    is a blank string ("") then this is equivalen to an argument of
    "@stderr" (the default destination).

    @returns
    0 on success, non-zero otherwise.  If an error occurs a warning
    will also be raised using the standard VE error functions.
 */
int vePfDest(char *dest);

/** function vePfRecord
    <p>Tells the profiler to start recording any events passed to it.
    Events will be written to the current destination as specified
    by the most recent call to <code>vePfDest()</code>.</p>
*/
void vePfRecord(void);

/** function vePfFlush
    <p>Tells the profiler to flush any cached events to wherever they
    are being written.</p>
 */
void vePfFlush(void);

/** function vePfStop
    <p>Tells the profiler to stop recording any events passed to it.
    This also causes any stored events to be flushed.</p>
*/
void vePfStop(void);

/** function vePfPause
    <p>Like <code>vePfStop()</code> this will prevent the profiler from
    writing events, but it will not flush any cached events.  This function
    is meant to be used together with <code>vePfResume()</code> to create
    blocks of code that are deliberately not profiled.  See the description
    of <code>vePfResume()</code> for more information.
*/
void vePfPause(void);

/** function vePfResume
    <p>This function resumes event recording after a call to
    <code>vePfPause()</code>, if event recording was active at the time
    when <code>vePfPause()</code> was called.  That is, this returns the
    state of event recording to whatever it was when <code>vePfPause()</code>
    was called.</p>
*/
void vePfResume(void);

/** function vePfIsPaused
    <p>Checks to see if we are currently in-between 
    <code>vePfPause()</code>/<code>vePfResume()</code> calls.
    
    @returns
    0 if recording of events is not paused, non-zero if <code>vePfIsPaused()</code>
    has been called without a corresponding call to <code>vePfResume()</code>.
*/
int vePfIsPaused(void);

/** function vePfIsActive
    <p>Checks to see if events are being recorded.  This wil be true
    if <code>vePfRecord()</code> has been called (and <code>vePfStop()</code>
    has not) regardless of whether or not recording is currently paused.</p>

    @returns
    0 if events are not being recorded, non-zero otherwise.
 */
int vePfIsActive(void);

/** function vePfEvent
    This is the function that is called by other modules to report a 
    profiling event.

    @param module
    The name of the module from which this event originates.

    @param event
    A name for the event.  Names in lower-case characters without
    spaces are preferred.

    @param fmt
    A printf-style format string, followed by values to format.
    If this value is <code>NULL</code> then no printf-style formatting
    will be done (any further arguments are ignored).
*/
void vePfEvent(char *module, char *event, char *fmt, ...);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* VE_PROFILER_H */
