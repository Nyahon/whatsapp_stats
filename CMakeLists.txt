cmake_minimum_required(VERSION 3.7)
project(projects)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp conv.cpp conv.h message.cpp message.h utils.hpp ../whatsappExtractFromDump.hpp ../convData.cpp ../convData.h)
add_executable(projects ${SOURCE_FILES})