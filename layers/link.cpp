#include "link.h"
#include <iostream>

std::string Link_Send(const std::string& data) {
    const std::string frame = "LINK_HDR|" + data;
    std::cout << "[Link Layer] Sending: " << frame << std::endl;
    return frame;
}

std::string Link_Receive(const std::string& data) {
    std::cout << "[Link Layer] Receiving: " << data << std::endl;
    const std::string prefix = "LINK_HDR|";
    if (data.rfind(prefix, 0) == 0) {
        return data.substr(prefix.size());
    }
    return data;
}
