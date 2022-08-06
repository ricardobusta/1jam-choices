#
# Created by Ricardo Bustamante <ricardo@busta.dev> on 06/08/2022.
#
cmake_minimum_required(VERSION 3.22)
project(Game LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB_RECURSE ${PROJECT_NAME}_SRC CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/*.cpp)
file(GLOB ${PROJECT_NAME}_HEADERS CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/*.h ${PROJECT_SOURCE_DIR}/**/*.h)
include_directories(
        scenes
        components
)

set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_CURRENT_SOURCE_DIR}/appicon.rc")

set(HARPIA_APPLICATION_TYPE "")

if (CMAKE_BUILD_TYPE MATCHES Debug)
else ()
    if (WIN32)
        set(HARPIA_APPLICATION_TYPE WIN32)
    endif ()
endif ()

add_executable(${PROJECT_NAME} ${HARPIA_APPLICATION_TYPE} ${${PROJECT_NAME}_SRC} ${APP_ICON_RESOURCE_WINDOWS})
target_sources(${PROJECT_NAME} PUBLIC ${${PROJECT_NAME}_SRC} ${${PROJECT_NAME}_HEADERS})
target_link_libraries(${PROJECT_NAME} PUBLIC Harpia)

# for assets on debug builds
# New-Item -ItemType SymbolicLink -Target ".\game\assets" -Path ".\cmake-build-debug\bin\assets"