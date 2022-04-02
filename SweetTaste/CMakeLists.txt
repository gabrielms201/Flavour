# Project Specs
cmake_minimum_required(VERSION 3.17.0)
project("SweetTaste")
message("Building: ${PROJECT_NAME}")

# Platform Specifications
if(WIN32)
    message("\t ${PROJECT_NAME}: I do provide Windows support")
elseif(UNIX)
    message("\t ${PROJECT_NAME}: I do provide Unix support")
else()
    message("\t ${PROJECT_NAME}: Unfortunately I can't support your system. Windows and Unix Support Only")
endif()

# Build Config
add_executable("${PROJECT_NAME}")
target_sources("${PROJECT_NAME}" PRIVATE
    "main.cpp"
)
install(TARGETS "${PROJECT_NAME}" DESTINATION bin)

# Dependencies Config
SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES PREFIX "")
set(CMAKE_SHARED_LIBRARY_PREFIX "")

# Add pre build instruction to copy dynamic library into the project folder
if(WIN32)
    set(FLAVOUR_LIB_DYNAMIC_TYPE "Flavour.dll")
elseif(UNIX)
    set(FLAVOUR_LIB_DYNAMIC_TYPE "Flavour.so")
endif()
add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${CMAKE_BINARY_DIR}/Flavour/${CMAKE_CFG_INTDIR}/${FLAVOUR_LIB_DYNAMIC_TYPE}" "${CMAKE_BINARY_DIR}/${PROJECT_NAME}/${CMAKE_CFG_INTDIR}")



target_include_directories("${PROJECT_NAME}" PRIVATE "${CMAKE_BINARY_DIR}/../Flavour/")
target_include_directories("${PROJECT_NAME}" PRIVATE "${CMAKE_BINARY_DIR}/../Flavour/Dependencies/spdlog/include")
target_link_directories("${PROJECT_NAME}" PRIVATE "${CMAKE_BINARY_DIR}/../Flavour")
target_link_libraries("${PROJECT_NAME}" PRIVATE "Flavour")


