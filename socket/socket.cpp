#include "socket.h"
using namespace std;

Socket::Socket() : 
    server_fd(::socket(AF_INET,SOCK_STREAM,0)){
    // This will create the socket and prep it for listening
    // creating the socket.
    if(server_fd < 0){
        cout << "Error creating socket ... exiting with failure.\n";
        exit(EXIT_FAILURE);
    }
    cout << "Socket created with success.\n";
}

void Socket::bind(int port){
    // configure socket address.
    address.sin_family = AF_INET;         // IP
    address.sin_addr.s_addr = INADDR_ANY; // VCS
    address.sin_port = htons(port);
    memset(address.sin_zero, '\0', sizeof address.sin_zero);
    // Binding the socket , its like identifing it.   
    if (::bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0)
    {
        cout << "Error Binding the socket ... exiting with failure.\n";
        exit(EXIT_FAILURE);
    }
    cout << "Binding socket successfull !\n";
}

void Socket::connect(int port){
    // configuring to socket to connect to another to prepare to send messages to another.
    memset(&address,0,sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(port);

    // Convert IPv4 and IPv6 addresses from text to binary form
    // the ip will change when the server is hosted in another machine other then locally.
    if(inet_pton(AF_INET, "127.0.0.1", &address.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        exit(EXIT_FAILURE);
    }
    if (::connect(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        printf("\nConnection Failed \n");
        exit(EXIT_FAILURE);
    }
    cout << "connecting to socket successfull !\n";
}
Socket::~Socket(){
    close(server_fd);
}
