#include "../include/server.h"
using namespace std;

server::server(shelf *books_db,auth *users_db){
    books = unique_ptr<shelf>(books_db);
    users = unique_ptr<auth>(users_db);
}
server::~server(){
    // closing the socket.
    close(server_fd);
}
void server::createSocket(int port){
    // This will create the socket and prep it for listening
    // creating the socket.
    if((server_fd = socket(AF_INET,SOCK_STREAM,0)) < 0){
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
void server::handleRequests(){
    // begin listening for requests 
    if(listen(server_fd,connection_log) != 0){
        cout << "Error listening to a socket ... exiting with failure.\n";
        exit(EXIT_FAILURE);
    }
    cout << "Listening for requests ...\n"; 
    cout << "\n+++++++ Waiting for new connection ++++++++\n";
    while(1){
        // Here we accept a request
        if((new_socket = accept(server_fd,(struct sockaddr *)&address,(socklen_t*)sizeof(address))) < 0){
            cout << "Error accepting the request ... ignored.\n";
            cout << "------------------Failed-------------------\n";
            continue;
        }
        cout << "<connected>...\n";
        // here we can display more info about the sender.
        int pid = fork(); 
        if(pid == 0){
            break;
        }
    }
    // Handle / read do stuff.
    cout << "------------------Response has been sent-------------------\n";
    close(new_socket);
    close(server_fd);
    // child process returns from this function to the main where memory is freed and exits 
    // gracfully.
}
