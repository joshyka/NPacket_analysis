cmake_minimum_required(VERSION 3.0.0)
project(packet_analyzer)

include(CTest)
enable_testing()

add_executable(packet_analyzer packetTracer.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
