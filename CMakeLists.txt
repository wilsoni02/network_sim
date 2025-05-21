cmake_minimum_required(VERSION 3.0)
project(network_sim)

set(CMAKE_CXX_STANDARD 17)

add_executable(network_sim main.cpp layers/application.h layers/application.cpp layers/link.cpp layers/network.cpp layers/transport.cpp)
