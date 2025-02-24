// here i will define the base uses of a socket such that the server class and the client side 
// will inherite from the socket + impliment there own shit
// more methodes will be added by future me later , just seeing if things wor k or not
#pragma once
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <iostream>

class Socket {
public:
    static const int buffer_size = 300;
    // this is used to check if a socket is already created and if so 
    // overwrites it if we try to create another
    // files desciptor for our socket
    const int server_fd;
    // fd for the reponse socket
    int new_socket;
    // tells us how much bytes (i think) we read.
    long values_read;
    // additional info about our socket
    struct sockaddr_in address;
    // this tells us how many user can stack up in queue to be served.
    int connection_log = 10;
    // i went with a constante buffer that can be overwritten.
    char buffer[buffer_size]; 
    // gonna use ol C. 
    // options that are used to create the socket will remained constant and managed by the methode.
    Socket();
    // to allow for more flexibility , we will leave the configuration of the socket to the using class.
    // this is gonna be used for the server side of the program.
    void bind(int port);
    // this is conserning the the client side of the program 
    // i do leave the complete freedome of messing this up untile i find another way.
    void connect(int port);
    ~Socket();
};
