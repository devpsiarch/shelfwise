#include <iostream>
#include "../include/Book.h"
#include "../include/shelf.h"
#include "../include/db.h"
#include <mariadb/conncpp.hpp>
#include "../Auth/Auth.h"
using namespace std;
using namespace sql;

int main(void) {
    try {
        vector<string> *creds = shelf::readCreds("conf.shelf");
        if(creds == nullptr){
            cout << "could not read the conf file \n";
            return 0;
        };
        // these are the attibutes of the books db
        shelf *books = new shelf(*creds);
        books->showShelf();
        delete creds;
        delete books;
    }catch(const exception& e){
        cout << "exception accured error : " << e.what() << "\n";
    }
    return 0;
}
