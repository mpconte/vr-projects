#ifndef VE_VERSION_H
#define VE_VERSION_H

#ifdef __cplusplus
extern "C" {
#endif

/** misc
    This module provides information about the current VE
    version both at compile and run time.  It only exists in 
    VE 2.2 and later.  It is included by all other VE headers
    so compile-time macros can be used in existing code without
    referring to this header file (see details below).
    <p>VE's version number consists of three parts:  a major
    version, a minor version and a patch level.  For example,
    the initial VE 2.2 release is major version 2, minor version
    2 and patch level 0.  This is usually written as a string
    with the values separated by dots, e.g. "2.2.0".
    <p>We define two forms of compatibility.  "Binary compatibility"
    refers to the compiled form of an application or module and implies
    that recompilation is not necessary.  "Source compatibility"
    means that the original source code should compile against the
    given VE version, but that a version of the source code compiled
    against a previous version of VE may not be compatible.
    The following compatibility rules generally apply to
    different VE versions.
    <ul>
    <li>Code compiled against a particular version of VE is
    not guaranteed to be compatible with any previous version
    of VE.</li>


    <li>Applications compiled against a particular version of 
    VE will be binary compatible against any later patch revisions
    of VE.  Such applications are likely to binary compatible
    with later minor revisions of VE.  Such applications are
    most likely not binary compatible with later major
    revisions of VE.  For example, given an application
    compiled against VE 2.1.3, it will be binary compatible
    with  VE 2.1.5.  It will likely be binary compatible with
    VE 2.2.0 but this is not guaranteed.  It is unlikely
    to be binary compatible with VE 3.0.0.
    </li>

    <li>Applications that compile against a particular version of
    VE will be source compatible with any later patch or minor
    revision of VE.  Such applications may be source 
    compatibile with later major revisions of VE but this
    compatibility is not guaranteed.</li>

    <li>Drivers (i.e. modules loaded at run-time as shared
    objects that provide filters, device drivers, audio
    drivers, or use other VE extension mechanisms) will
    be  compatible with any later patch revisions of
    VE. Such drivers are unlikely to be compatible with
    later major and minor revisions of VE.  For example, given
    a driver compiled against VE 2.1.3, it will be
    compatible with VE 2.1.5.  It is unlikely to be
    compatible with VE 2.2.0 or VE 3.0.0.  Note that this
    rule applies to both binary compatibility and source
    compatibility.</li>

    <li><em>Any</em> application or module that allocates
    storage for VE objects itself (via a call to malloc() or
    its equivalent) or locally declares variables for VE
    structures that are not pointers have no binary compatibility
    guarantees at all regardless of any other rule listed here.
    For example, if your module defines a variable like 
    <code>VeDeviceEvent e</code> then it will not be binary
    compatible.  If you define a variable as <code>VeDeviceEvent
    *e</code> and use a VE function to create the object
    (for this example, <code>veDeviceEventCreate()</code>) then
    the binary compatiblity rules below will apply.</li>

    </ul>

*/

/** section Compile-Time Versions
    
    Macros allow drivers and applications to test the version of
    VE that they are being compiled against.  This allows code to
    determine the availability of various interfaces, types, functions,
    etc.  The following macros are defined:

    <ul>
    <li><code>VE_VERSION_MAJOR</code> - an integer representing the
    major version of VE being compiled against.</li>
    <li><code>VE_VERSION_MINOR</code> - an integer representing the
    minor version of VE being compiled against.</li>
    <li><code>VE_VERSION_PATCH</code> - an integer representing the
    patch version of VE being compiled against.</li>
    <li><code>VE_VERSION_STRING</code> - a string constant containing
    the string version (e.g. "2.2.0").
    </ul>

    These macros were introduced in VE 2.2.0.  The macro 
    <code>VE_HAS_VERSION</code> is defined as a non-zero
    integer in VE 2.2 and later.  It is undefined in earlier
    versions.  Any source code
    which may be compiled against an earlier version of VE must
    be careful in testing this macro, e.g.
<blockquote><pre>#if defined(VE_HAS_VERSION) && VE_VERSION_MAJOR &gt; 2</pre></blockquote>
    
*/

/** section Run-Time Versions
    
   There are also functions to determine the version of VE
   which is being used as a run-time environment.  These functions
   are only available in VE 2.2 and later.  If source code must
   be compatible with earlier VE versions, then the use of these
   functions must be guarded with the <code>VE_HAS_VERSION</code>
   macro (see above).

 */

/** function veGetVersionMajor
    @returns
    The current major version of the VE run-time as an
    integer.
 */
int veGetVersionMajor(void);

/** function veGetVersionMinor
    @returns
    The current minor version of the VE run-time as an
    integer.
 */
int veGetVersionMinor(void);

/** function veGetVersionPatch
    @returns
    The current patch version of the VE run-time as an
    integer.
 */
int veGetVersionPatch(void);

/** function veGetVersionString
    @returns
    The current version string of the VE run-time.
    This string should be treated as read-only.
 */
char *veGetVersionString(void);


/* the following macro should always be set to 1 in VE 2.2
   and later */
#define VE_HAS_VERSION     1

/* actual version numbers follow */

#define VE_VERSION_MAJOR   2
#define VE_VERSION_MINOR   2
#define VE_VERSION_PATCH   0

/* the following should not need to change */

#define VE_VERSION_MKSTR(maj,min,pat) #maj "." #min "." #pat

#define VE_VERSION_STRING VE_VERSION_MKSTR(VE_VERSION_MAJOR,VE_VERSION_MINOR,VE_VERSION_PATH)

#ifdef __cplusplus
}
#endif

#endif /* VE_VERSION_H */
