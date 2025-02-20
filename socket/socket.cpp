#include "socket.h"
using namespace std;

Socket::Socket(int port) : 
    server_fd(::socket(AF_INET,SOCK_STREAM,0)){
    // This will create the socket and prep it for listening
    // creating the socket.
    if(server_fd < 0){
        cout << "Error creating socket ... exiting with failure.\n";
        exit(EXIT_FAILURE);
    }
    // configure socket address.
    address.sin_family = AF_INET;         // IP
    address.sin_addr.s_addr = INADDR_ANY; // VCS
    address.sin_port = htons(port);
    memset(address.sin_zero, '\0', sizeof address.sin_zero);
    // Binding the socket , its like identifing it.   
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0)
    {
        cout << "Error Binding the socket ... exiting with failure.\n";
        exit(EXIT_FAILURE);
    }
    cout << "Socket created with success.\n";
}

Socket::~Socket(){
    close(server_fd);
}
