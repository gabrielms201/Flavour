# Project Specs
cmake_minimum_required(VERSION 3.17.0)
project("Flavour")
message("Building: ${PROJECT_NAME} Solution")

# Platform Specifications
if(WIN32)
    message("\t ${PROJECT_NAME}: I do provide Windows support")
elseif(UNIX)
    message("\t ${PROJECT_NAME}: I do provide Unix support")
else()
    message("\t ${PROJECT_NAME}: Unfortunately I can't support your system. Windows and Unix Support Only")
endif()

# Projects
include_directories(${CMAKE_CURRENT_BINARY_DIR})
add_subdirectory("Flavour")
add_subdirectory("SweetTaste")