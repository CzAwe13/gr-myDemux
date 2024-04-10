# Copyright 2020 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

########################################################################
# Check if there is C++ code at all
########################################################################
if(NOT myDemux_sources)
    MESSAGE(STATUS "No C++ sources... skipping python bindings")
    return()
endif(NOT myDemux_sources)

########################################################################
# Check for pygccxml
########################################################################
GR_PYTHON_CHECK_MODULE_RAW(
    "pygccxml"
    "import pygccxml"
    PYGCCXML_FOUND
    )

include(GrPybind)

########################################################################
# Python Bindings
########################################################################

list(APPEND myDemux_python_files
    my_header_payload_demux_python.cc python_bindings.cc)

GR_PYBIND_MAKE_OOT(myDemux
   ../../..
   gr::myDemux
   "${myDemux_python_files}")

# copy bindings extension for use in QA test module
add_custom_command(TARGET myDemux_python POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:myDemux_python>
    ${PROJECT_BINARY_DIR}/test_modules/gnuradio/myDemux/
)

install(TARGETS myDemux_python DESTINATION ${GR_PYTHON_DIR}/gnuradio/myDemux COMPONENT pythonapi)
