#include "transport.h"
#include <iostream>

std::string Trans_Send(const std::string& data) {
    const std::string segment = "TRANS_HDR|" + data;
    std::cout << "[Transport Layer] Sending: " << segment << std::endl;
    return segment;
}

std::string Trans_Receive(const std::string& data) {
    std::cout << "[Transport Layer] Receiving: " << data << std::endl;
    const std::string prefix = "TRANS_HDR|";
    if (data.rfind(prefix, 0) == 0) {
        return data.substr(prefix.size());
    }
    return data;
}