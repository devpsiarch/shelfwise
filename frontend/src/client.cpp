#include "../include/client.h"
using namespace std;

client::client(int port){
    SOCK = new Socket(port);
    SOCK->address.sin_addr.s_addr = 0;
}

void client::connect(char* ip_address){
    // converting the ip address to a integer
    if(inet_pton(AF_INET,ip_address,&SOCK->address.sin_addr) <= 0){
        cout << "Error while converting the ip address to a integer ...\n";
        exit(EXIT_FAILURE);
    }
    // connecting to socket
    if(::connect(SOCK->server_fd,(struct sockaddr *)&SOCK->address,sizeof(SOCK->address)) < 0){
        cout << "Error connecting to the socket ...\n";
        exit(EXIT_FAILURE);
    }
    cout << "Connected to socket with success !\n";
}

void client::sendrequest(char *message,int len){
    if(send(SOCK->server_fd,message,len,0) < 0){
        cout << "Sending the request failed ... moving on.\n";
        return;
    }
    cout << "Sent with success!\n";
}
client::~client(){
    delete SOCK;
}
