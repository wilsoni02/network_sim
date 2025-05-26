# network_sim

C++ simulation of the classic network stack:
Application → Transport → Network → Link.

**Created by:** Ian Wilson, Kamile Vaicekonis & Manxi Muhirwa  
**Date:** May 26, 2025  
**Course:** CSC4750 – Computer Networks

## Overview

This project demonstrates how simple message traverses the four layers of the network stack:
1. Application
2. Transport
3. Network
4. Link

Each layer adds its own header when sending and strips it when receiving.

## Project Structure

```
.
├── CMakeLists.txt        # CMake build configuration
├── main.cpp              # send and receive
├── layers/
│   ├── application.h     # App_Send & App_Receive
│   ├── application.cpp
│   ├── transport.h       # Trans_Send & Trans_Receive
│   ├── transport.cpp
│   ├── network.h         # Net_Send & Net_Receive
│   ├── network.cpp
│   ├── link.h            # Link_Send & Link_Receive
│   └── link.cpp
└── README.md
```

## Prerequisites

- C++17 compatible compiler (g++ or clang++)
- CMake version 3.10 or higher (optional, for CMake build)

## Build and Run

### Using CMake

```bash
mkdir -p build
cd build
cmake ..
make
./network_sim
```

### Manual Compilation

```bash
g++ -std=c++17 -Ilayers \
  main.cpp \
  layers/application.cpp layers/transport.cpp \
  layers/network.cpp layers/link.cpp \
  -o network_sim

./network_sim
```

## How It Works

This simulation demonstrates the Internet Protocol Stack by showing how data is encapsulated for data transmission and decapsulated for reception. Each layer has a specific job that relates the software sending data to the networking hardware, which allows for efficient and reliable data sharing.
For this simulation, the Physical Layer is excluded.

This is the process of our simulation:

1. Application Layer adds its header and passes the message to Transport.
2. Transport Layer adds its header and passes it to Network.
3. Network Layer adds its header and passes it to Link.
4. Link Layer transmits the framed message.
5. On receipt, each layer in reverse order removes its header and passes the payload up.

During transmission, each layer adds a header to the original message, encapuslating the data. During decapsulation, the headers are removed in reverse order, leaving only the original message. This reflects how the Internet Protocol Stack handles data. The process is intuitive because data must pass from the Application Layer to the Transport, Network, and Link Layers before reaching the networking hardware for transmission.
