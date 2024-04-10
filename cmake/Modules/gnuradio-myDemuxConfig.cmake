find_package(PkgConfig)

PKG_CHECK_MODULES(PC_GR_MYDEMUX gnuradio-myDemux)

FIND_PATH(
    GR_MYDEMUX_INCLUDE_DIRS
    NAMES gnuradio/myDemux/api.h
    HINTS $ENV{MYDEMUX_DIR}/include
        ${PC_MYDEMUX_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    GR_MYDEMUX_LIBRARIES
    NAMES gnuradio-myDemux
    HINTS $ENV{MYDEMUX_DIR}/lib
        ${PC_MYDEMUX_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/gnuradio-myDemuxTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GR_MYDEMUX DEFAULT_MSG GR_MYDEMUX_LIBRARIES GR_MYDEMUX_INCLUDE_DIRS)
MARK_AS_ADVANCED(GR_MYDEMUX_LIBRARIES GR_MYDEMUX_INCLUDE_DIRS)
