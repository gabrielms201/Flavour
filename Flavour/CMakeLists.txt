# Project Specs
cmake_minimum_required(VERSION 3.17.0)
project("Flavour")
message("Building: ${PROJECT_NAME}")
set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")
set(CMAKE_SHARED_MODULE_PREFIX "")

# Platform Specifications
if(WIN32)
    message("\t ${PROJECT_NAME} speaking: I do provide Windows support")
    add_compile_definitions("FLAVOUR_WIN_EXPORT")
elseif(UNIX)
    message("\t ${PROJECT_NAME} speaking: I do provide Unix support")
else()
    message("\t ${PROJECT_NAME} speaking: Unfortunately I can't support your system. Windows and Unix Support Only")
endif()

# MSVC .def file:
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(WIN_EXPORT_SYMBOLS "src/Flavour.def")
else()
    set(WIN_EXPORT_SYMBOLS "")
endif()

# Organizing the folders / source files

# Event System Source Folder
set(MAIN_SRC
    "src/Flavour.h"
    "src/stdafx.h"
    "src/stdafx.cpp"
)

set(EVENT_SRC
    "src/Core/Events/Event.h"
    "src/Core/Events/KeyEvent.h"
    "src/Core/Events/ApplicationEvent.h"
    "src/Core/Events/MouseEvent.h"

    )
# Core Source Folder
set(CORE_SRC
    "src/Core/Application.cpp"
    "src/Core/Log.cpp"
    "src/Core/Application.h"
    "src/Core/EntryPoint.h"
    "src/Core/FlavourUtils.h"
    "src/Core/Log.h"

)
# All Source Folders
set(ALL_SRC
    ${MAIN_SRC}
    ${CORE_SRC}
    ${EVENT_SRC}

)
# Include Directories
include_directories(
    "dependencies/spdlog/include/"

)

# GROUP_SRC Macro
GROUP_SRC(ALL_SRC)

# Pointing all source folders
add_library(${PROJECT_NAME} SHARED ${WIN_EXPORT_SYMBOLS}
    ${ALL_SRC}
)
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")
include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/Flavour/src)
install(TARGETS "${PROJECT_NAME}" DESTINATION bin)

target_precompile_headers(${PROJECT_NAME} PRIVATE
    "src/stdafx.h"
    "src/stdafx.cpp")

#[[ Some unused commands:
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
    # Other way to organize the solution:
    source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES 
        ${CORE_SRC}
        ${EVENT_SRC}
        )
]]


