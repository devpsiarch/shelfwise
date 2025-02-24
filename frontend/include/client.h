// this will have the implimentation that the front end will use to interact 
// remotly though socket with the server
// the driver for this will probebely be in the QT cpp files in the directoy above
#include "../../socket/socket.h"
#pragma once
class client  {
// connection methode provided by socket class
public:
    Socket* SOCK;
    client(int port);
    void sendrequest(char *message,int len);
    void readresponse();
    ~client();
};

