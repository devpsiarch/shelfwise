#include "../include/server.h"
using namespace std;

server::server(shelf *books_db,auth *users_db,int port){
    books = unique_ptr<shelf>(books_db);
    users = unique_ptr<auth>(users_db);
    SOCK = new Socket(port);
}
server::~server(){
    // closing the socket.
    delete SOCK;
}

void server::printWho(){
    // we already have the specification about the connection.
    // maybe if we offered more choices in the future.
    char ip_buffer[INET6_ADDRSTRLEN]; // holds the ip string
    char hostname_buffer[NI_MAXHOST]; // holds the hostname string

    inet_ntop(AF_INET,&SOCK->address.sin_addr,ip_buffer,sizeof(ip_buffer));
    
    printf("IP : %s\n",ip_buffer);
    
    int rc = getnameinfo((struct sockaddr*)&SOCK->address, sizeof(SOCK->address),
                     hostname_buffer, sizeof(hostname_buffer), NULL, 0, NI_NAMEREQD);
    
    // on success
    if(rc == 0){
        printf("hostname gotten : %s\n",hostname_buffer);
    }else {
        printf("Hostnamte lookup failed\n");
    }
}
void server::handleRequests(){
    // begin listening for requests 
    if(listen(SOCK->server_fd,SOCK->connection_log) != 0){
        cout << "Error listening to a socket ... exiting with failure.\n";
        exit(EXIT_FAILURE);
    }
    cout << "Listening for requests ...\n"; 
    int addrlen = sizeof(SOCK->address); 
    while(1){
        cout << "\n+++++++ Waiting for new connection ++++++++\n";
        // Here we accept a request
        SOCK->new_socket = accept(SOCK->server_fd,(struct sockaddr *)&SOCK->address,(socklen_t*)&addrlen);
        if(SOCK->new_socket < 0){
            //cout << "Error accepting the request ... ignored.\n";
            perror("IN accepting\n");
            printWho();
            cout << "------------------Failed-------------------\n";
            continue;
        }
        cout << "<connected>...\n";
        // here we can display more info about the sender.
        printWho();
        int pid = fork(); 
        if(pid == 0){
            break;
        }
    }
    // we only read and hanle when the message sent is valid (child proces broke out of the above loop).
    // Handle / read do stuff.
    int values_read = read(SOCK->new_socket,SOCK->buffer,300);  // Well need this later when cheking errors for 
    // valid messages sent over the socket.
    printf("message recieved : %.*s\n",values_read,SOCK->buffer); 
    cout << "------------------Response has been sent-------------------\n";
    // not allowed , 
    // handling will be much more updated later.
    char* respose = "well recieved";
    write(SOCK->new_socket,respose,strlen(respose));
    close(SOCK->new_socket);
    close(SOCK->server_fd);
    // child process returns from this function to the main where memory is freed and exits 
    // gracfully.
}
