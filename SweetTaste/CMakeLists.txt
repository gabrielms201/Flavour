cmake_minimum_required(VERSION 3.17.0)

project("SweetTaste")
message("Building: ${PROJECT_NAME}")
# Platform Specifications
if(WIN32)
    message("\t ${PROJECT_NAME}: I do provide Windows support")
elseif(UNIX)
    message("\t ${PROJECT_NAME}: I do provide Unix Suport")
else()
    message("\t ${PROJECT_NAME}: Unfortunately I can't support your system. Windows and Unix Support Only")
endif()

add_executable("${PROJECT_NAME}")
install(TARGETS "${PROJECT_NAME}" DESTINATION bin)

target_sources("${PROJECT_NAME}" PRIVATE
    "main.cpp"
)

target_include_directories("${PROJECT_NAME}" PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../Flavour/"
)


