cmake_minimum_required(VERSION 3.4)
project(STK)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)

find_library(CORE_AUDIO CoreAudio)
find_library(CORE_MIDI CoreMIDI)
find_library(CORE_FOUNDATION CoreFoundation)
find_package(Threads REQUIRED)

# Find source files
file(GLOB SOURCES src/*.cpp)

# Include header files
include_directories(include)
include_directories(src/include)

# Create shared library
add_library(${PROJECT_NAME} SHARED ${SOURCES} )

target_link_libraries(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/libstk.a ${CORE_AUDIO} ${CORE_MIDI} ${CORE_FOUNDATION} ${CMAKE_THREAD_LIBS_INIT})

