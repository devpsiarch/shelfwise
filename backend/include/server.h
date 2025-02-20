// note : make an abstract object that handles the network stuff and create "server" and "client" objects 
// that inherite from the latter (while using the UNIX utils to comunicate over a socket).

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
#include "../include/socket.h"

using namespace std;
class server : public socket{
private:
    // we use the unique here to delete the pointers as soon as the object is dead
    unique_ptr<shelf> books;
    unique_ptr<auth> users;
// the methodes here may be changed if seen fit for socket class
public:
    server(shelf *books_db,auth *users_db);
    ~server();
    // This will listen , accept and handle every requst 
    // multthreading implimented.
    void handleRequests();
    // This will display additional information about who sends the requests to the log 
    // i thought this will be important to see what the hell is going on    
    void whoRequested();
    // here iwanted to know more abourt who made the request 
    void printWho();
};
