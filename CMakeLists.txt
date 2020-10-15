cmake_minimum_required(VERSION 3.12)

project(unified VERSION 0.0.1)

message("Building the UnifiedEngine version ${PROJECT_VERSION}")

set(CMAKE_CXX_STANDARD 17)

set(UNIFIED_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(UNIFIED_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(UNIFIED_VENDOR_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vendor")

set(UNIFIED_EXAMPLE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/example")

file(GLOB_RECURSE UNIFIED_SRC_FILES "${UNIFIED_SRC_DIR}/*.cpp")
file(GLOB_RECURSE UNIFIED_INCLUDE_FILES "${UNIFIED_INCLUDE_DIR}/*.hpp")

add_library(${PROJECT_NAME} STATIC ${UNIFIED_SRC_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC "${UNIFIED_INCLUDE_DIR}/")

# Setting of special macro definitions
target_compile_definitions(${PROJECT_NAME} INTERFACE "UNIFIED_LIBRARY")
target_compile_definitions(${PROJECT_NAME} INTERFACE "$<$<CONFIG:DEBUG>:_DEBUG_>")
target_compile_definitions(${PROJECT_NAME} INTERFACE "$<$<CONFIG:RELEASE>:_RELEASE_>")

# Including the 'osl' library
set(UNIFIED_OSL_DIR "${UNIFIED_VENDOR_DIR}/osl")
target_include_directories(${PROJECT_NAME} PUBLIC "${UNIFIED_OSL_DIR}/libs/")

# Including the 'fmt' library
set(UNIFIED_FMT_DIR "${UNIFIED_VENDOR_DIR}/fmt/")
add_subdirectory(${UNIFIED_FMT_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE fmt)

# Including the 'glfw' library
set(UNIFIED_GLFW_DIR "${UNIFIED_VENDOR_DIR}/glfw")
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "")
set(GLFW_INSTALL OFF CACHE INTERNAL "")
add_subdirectory("${UNIFIED_GLFW_DIR}/")
target_link_libraries(${PROJECT_NAME} PRIVATE "glfw" ${GLFW_LIBRARIES})

option(UNIFORM_BUILD_TESTS "Build the UnifiedEngine test program" TRUE)

if (UNIFORM_BUILD_TESTS)
 message("Building the UnifiedEngine test program")
 add_subdirectory("${UNIFIED_EXAMPLE_DIR}/")
endif ()