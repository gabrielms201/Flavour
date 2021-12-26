# Project Specs
cmake_minimum_required(VERSION 3.17.0)
project("Flavour")
message("Building: ${PROJECT_NAME}")
set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")
set(CMAKE_SHARED_MODULE_PREFIX "")

# Platform Specifications
if(WIN32)
    message("\t ${PROJECT_NAME}: I do provide Windows support")
    add_compile_definitions("FLAVOUR_WIN_EXPORT")
elseif(UNIX)
    message("\t ${PROJECT_NAME}: I do provide Unix support")
else()
    message("\t ${PROJECT_NAME}: Unfortunately I can't support your system. Windows and Unix Support Only")
endif()

# MSVC .def file:
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(WIN_EXPORT_SYMBOLS "Flavour.def")
else()
    set(WIN_EXPORT_SYMBOLS "")
endif()

# Source Files
add_library("${PROJECT_NAME}" SHARED "${WIN_EXPORT_SYMBOLS}"
    "Core/Application.cpp"
    "Core/Application.h"
    "Core/EntryPoint.h"
    "Core/PlatformExport.h"
    "Flavour.h"
)
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")
include_directories(${CMAKE_CURRENT_BINARY_DIR})
install(TARGETS "${PROJECT_NAME}" DESTINATION bin)




