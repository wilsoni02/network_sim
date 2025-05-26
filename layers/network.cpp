#include "network.h"
#include <iostream>

std::string Net_Send(const std::string& data) {
    const std::string packet = "NET_HDR|" + data;
    std::cout << "[Network Layer] Sending: " << packet << std::endl;
    return packet;
}

std::string Net_Receive(const std::string& data) {
    std::cout << "[Network Layer] Receiving: " << data << std::endl;
    const std::string prefix = "NET_HDR|";
    if (data.rfind(prefix, 0) == 0) {
        return data.substr(prefix.size());
    }
    return data;
}
