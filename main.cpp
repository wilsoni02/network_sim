// network_sim project created by:
// Ian Wilson, Kamile Vaicekonis & Manxi Muhirwa
// May 29th 2025, CSC4750 Computer Networks

#include <iostream>
#include <string>
#include "application.h"  // provides App_Send, App_Receive
#include "transport.h"    // provides Trans_Send, Trans_Receive
#include "network.h"      // provides Net_Send, Net_Receive
#include "link.h"         // provides Link_Send, Link_Receive

int main() {
    // Original message at the Application layer
    std::string message = "Hello, Network!";
    std::cout << "Message sent: " << message << std::endl << std::endl;

    std::cout << "==== Sending ====" << std::endl;
    std::string app_out   = App_Send(message);
    std::string trans_out = Trans_Send(app_out);
    std::string net_out   = Net_Send(trans_out);
    std::string link_out  = Link_Send(net_out);

    std::cout << std::endl;

    std::cout << "==== Receiving ====" << std::endl;
    std::string link_in   = Link_Receive(link_out);
    std::string net_in    = Net_Receive(link_in);n
    std::string trans_in  = Trans_Receive(net_in);
    std::string app_in    = App_Receive(trans_in);

    std::cout << std::endl;
    std::cout << "Final message received: " << app_in << std::endl;

    return 0;
}
