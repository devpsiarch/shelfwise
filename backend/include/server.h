#pragma once
// Am gonna try to keep it simple and easy for me to understand , 
// here we will define the functionality that is neccecary for our backend to be able to serve clients 
// using the app 
// this class will depend on the auth and shelf class that manage the databases since thats pretty much 
// what this app do ... 
// this will also construct responses that are dilivered to the client which the qt framework will interpret 
// to display things (for example info about a book that qt will draw a box using them).
// idk how good this implimentation is but hey , i hope someone reviews this code and points it out to me.

// Dont forget to impliment multi threading.
#include "../include/shelf.h"
#include "../include/auth.h"
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
using namespace std;
class server {
private:
    // we use the unique here to delete the pointers as soon as the object is dead
    unique_ptr<shelf> books;
    unique_ptr<auth> users;
    // files desciptor for our socket
    int server_fd;
    // fd for the reponse socket
    int new_socket;
    // tells us how much bytes (i think) we read.
    long values_read;
    // additional info about our socket
    struct sockaddr_in address;
    // this tells us how many user can stack up in queue to be served.
    int connection_log = 10;
    // i went with a constante buffer that can be overwritten.
    char buffer[300];
public:
    server(shelf *books_db,auth *users_db);
    ~server();
    // gonna use ol C. 
    // options that are used to create the socket will remained constant and managed by the methode.
    void createSocket(int port);
    // This will listen , accept and handle every requst 
    // multthreading implimented.
    void handleRequests();
    // This will display additional information about who sends the requests to the log 
    // i thought this will be important to see what the hell is going on    
    void whoRequested();
    // here iwanted to know more abourt who made the request 
    void printWho();
};
