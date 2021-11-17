cmake_minimum_required(VERSION 3.17.0)

project("Flavour")

message("Building: ${PROJECT_NAME}")
# Platform Specifications
if(WIN32)
    message("\t ${PROJECT_NAME}: I do provide Windows support")
elseif(UNIX)
    message("\t ${PROJECT_NAME}: I do provide Unix Suport")
else()
    message("\t ${PROJECT_NAME}: Unfortunately I can't support your system. Windows and Unix Support Only")
endif()

#add_library("${PROJECT_NAME}" )
add_library("${PROJECT_NAME}" SHARED
    "Core/Application.cpp"
    "Core/Application.h"
    "Core/EntryPoint.h"
    "Core/PlatformExport.h"
    "Flavour.h"
)
add_compile_definitions("FLAVOUR_WIN_EXPORT")
install(TARGETS "${PROJECT_NAME}" DESTINATION bin)



