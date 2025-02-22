#include <iostream>
#include "./include/client.h"
using namespace std;

int main(void){
    client sender = client(8080);
    // setting up the string since we are using good ol C in the backend.
    char* ip = (char*)malloc(sizeof(char)*25);
    strcpy(ip,"127.0.0.1");
    sender.connect(ip);
    // dummy message
    char* msg = (char*)malloc(sizeof(char)*25);
    strcpy(msg,"legenday");
    
    sender.sendrequest(msg,strlen(msg));
    free(msg);
    free(ip);
    return 0;
}
