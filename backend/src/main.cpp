#include <iostream>
#include "../include/book.h"
#include "../include/shelf.h"
#include "../include/auth.h"
#include "../include/db_conn.h"
#include "../include/server.h"
#include <mariadb/conncpp.hpp>
using namespace std;
using namespace sql;

int main(void) {
    try {
        vector<string> *creds = db_conn::readCreds("conf.shelf");
        if(creds == nullptr){
            cout << "could not read the conf file \n";
            return 0;
        };
        // creates a connector to handle queries to any database given a definition for.
        db_conn *main_db = new db_conn(*creds);
        // creating a obj that interracts with books/users db using main db handler above.
        shelf *books_db = new shelf(main_db);
        auth *users_db = new auth(main_db);
        
        server *shelfwise = new server(books_db,users_db);
        shelfwise->createSocket(8080);
        shelfwise->handleRequests(); 
        // Here the program has to wait and listen for an incoming requests and handle them 
        // accordingly and send back responses.
        // For now since am only trying to figure this out , am gonna take a raw approche
        // and use C socket to impliment said functionality 
        // This will kill the cross plateform but it will "hopefully" added later.


        
        delete shelfwise;
        delete creds;
        delete main_db;
    }catch(const exception& e){
        cout << "exception accured on main server ,code : " << e.what() << "\n";
    }
    return 0;
}
