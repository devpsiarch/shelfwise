#include "../include/client.h"
using namespace std;

client::client(int port){
    SOCK = new Socket();
    SOCK->connect(port);
}

void client::sendrequest(char *message,int len){
    if(send(SOCK->server_fd,message,len,0) < 0){
        cout << "Sending the request failed ... moving on.\n";
        return;
    }
    cout << "Sent with success!\n";
}

// I think this should return string ref later to be parsed and handeled.
void client::readresponse(){
    SOCK->values_read = read(SOCK->server_fd,SOCK->buffer,Socket::buffer_size);
    if(SOCK->values_read > Socket::buffer_size){
        exit(EXIT_FAILURE);
    }
    // prints only the nuber of chars read
    printf("Reponse from server : %.*s\n",SOCK->values_read,SOCK->buffer);
}

client::~client(){
    delete SOCK;
}
