cmake_minimum_required(VERSION 3.17.0)

project("Flavour")

message("Building: ${PROJECT_NAME}")
# Platform Specifications
if(WIN32)
    message("\t ${PROJECT_NAME}: I do provide Windows support")
elseif(UNIX)
    message("\t ${PROJECT_NAME}: I do provide Unix support")
else()
    message("\t ${PROJECT_NAME}: Unfortunately I can't support your system. Windows and Unix Support Only")
endif()

# Source Files
add_library("${PROJECT_NAME}" SHARED "Flavour.def"
    "Core/Application.cpp"
    "Core/Application.h"
    "Core/EntryPoint.h"
    "Core/PlatformExport.h"
    "Flavour.h"
)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES PREFIX "")
add_compile_definitions("FLAVOUR_WIN_EXPORT")
install(TARGETS "${PROJECT_NAME}" DESTINATION bin)




