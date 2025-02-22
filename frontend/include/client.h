// this will have the implimentation that the front end will use to interact 
// remotly though socket with the server
// the driver for this will probebely be in the QT cpp files in the directoy above
#include "../../socket/socket.h"
#pragma once
class client  {
public:
    Socket* SOCK;
    client(int port);
    // This will connect to the socket to be able to send messages.
    void connect(char* ip_address);
    void sendrequest(char *message,int len);
    ~client();
};

