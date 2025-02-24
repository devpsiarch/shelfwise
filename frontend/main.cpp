#include <iostream>
#include "./include/client.h"
using namespace std;

int main(void){
    client sender = client(8080);
    // setting up the string since we are using good ol C in the backend.
    // dummy message
    char* msg = (char*)malloc(sizeof(char)*25);
    strcpy(msg,"legenday");
    
    sender.sendrequest(msg,strlen(msg));
    sender.readresponse(); 
    free(msg);
    return 0;
}
