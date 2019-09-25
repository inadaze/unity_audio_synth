cmake_minimum_required(VERSION 3.14)
project(TestLibrary)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)

find_library(CORE_AUDIO CoreAudio)
find_library(CORE_MIDI CoreMIDI)
find_library(CORE_FOUNDATION CoreFoundation)
find_package(Threads REQUIRED)
add_library(TestLibrary SHARED library.cpp library.h Talker.cpp Talker.h)

#include_directories(/Users/jasons/Desktop/ConsoleApp1/cpp/LibStk/include/ /Users/jasons/Desktop/ConsoleApp1/cpp/LibStk/src/)
include_directories(../../cpp/LibStk/include/ ../../cpp/LibStk/src/)
#target_link_libraries(TestLibrary /Users/jasons/Desktop/ConsoleApp1/cpp/LibStk/src/libstk.a ${CORE_AUDIO} ${CORE_MIDI} ${CORE_FOUNDATION} ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(TestLibrary ${CMAKE_CURRENT_SOURCE_DIR}/../../cpp/LibStk/src/libstk.a ${CORE_AUDIO} ${CORE_MIDI} ${CORE_FOUNDATION} ${CMAKE_THREAD_LIBS_INIT})
