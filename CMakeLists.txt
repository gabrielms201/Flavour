# Project Specs
cmake_minimum_required(VERSION 3.17.0)
project("Flavour")
message("Building: ${PROJECT_NAME} Solution")

# Platform Specifications
if(WIN32)
    message("\t ${PROJECT_NAME} solution speaking: I do provide Windows support")
elseif(UNIX)
    message("\t ${PROJECT_NAME} solution speaking: I do provide Unix support")
else()
    message("\t ${PROJECT_NAME} solution speaking: Unfortunately I can't support your system. Windows and Unix Support Only")
endif()

# Macros

MACRO(GROUP_SRC SRCS)
  foreach(FILE IN LISTS ${SRCS}) 
    #convert source file to absolute
    string(REPLACE "src/" "" FILE ${FILE})
    #message(${FILE})
    get_filename_component(ABSOLUTE_PATH "${FILE}" ABSOLUTE)
    # Get the directory of the absolute source file
    get_filename_component(PARENT_DIR "${ABSOLUTE_PATH}" DIRECTORY)
    # Remove common directory prefix to make the group
    string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}" "" GROUP "${PARENT_DIR}")
    # Make sure we are using windows slashes
    string(REPLACE "/" "\\" GROUP "${GROUP}")
    message("${GROUP}")
    # Group into "Source Files" and "Header Files"
    if ("${FILE}" MATCHES ".*\\.cpp")
      set(GROUP "Source Files${GROUP}")
    elseif("${FILE}" MATCHES ".*\\.h")
      set(GROUP "Header Files${GROUP}")
    endif()
    source_group("${GROUP}" FILES "src/${FILE}")
  endforeach()
ENDMACRO(GROUP_SRC)

# Projects
include_directories(${CMAKE_CURRENT_BINARY_DIR})
add_subdirectory("Flavour")
add_subdirectory("SweetTaste")

