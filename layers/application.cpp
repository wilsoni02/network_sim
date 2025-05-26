#include "application.h"
#include <iostream>

std::string App_Send(const std::string& data) {
    const std::string payload = "APP_HDR|" + data;
    std::cout << "[Application Layer] Sending: " << payload << std::endl;
    return payload;
}

std::string App_Receive(const std::string& data) {
    std::cout << "[Application Layer] Receiving: " << data << std::endl;
    const std::string prefix = "APP_HDR|";
    if (data.rfind(prefix, 0) == 0) {
        return data.substr(prefix.size());
    }
    return data;
}