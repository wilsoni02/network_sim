cmake_minimum_required(VERSION 3.10)
project(network_sim)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(network_sim main.cpp layers/application.h layers/application.cpp layers/link.cpp layers/network.cpp layers/transport.cpp)
target_include_directories(network_sim PRIVATE ${CMAKE_SOURCE_DIR}/layers)
