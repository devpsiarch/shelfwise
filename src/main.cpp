#include <iostream>
#include "../include/book.h"
#include "../include/shelf.h"
#include "../include/auth.h"
#include <mariadb/conncpp.hpp>
using namespace std;
using namespace sql;

int main(void) {
    try {
        vector<string> *creds = shelf::readCreds("conf.shelf");
        if(creds == nullptr){
            cout << "could not read the conf file \n";
            return 0;
        };
        // makes a connection to the books database.
        shelf *books_db = new shelf(*creds);
        book *test = new book(
            "the bay at hand",
            "james miller",
            "12345678910111213",
            "EN",
            1990,
            "fiction",
            "yaho",
            600,
            "ebook",
            10
        );

        test->print();
        books_db->addBook(test);
        //books_db->rmoBook(test);
        books_db->showShelf();  

        delete test;
        delete creds;
        delete books_db;
    }catch(const exception& e){
        cout << "exception accured error : " << e.what() << "\n";
    }
    return 0;
}
