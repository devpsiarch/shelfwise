#include <iostream>
#include "../include/book.h"
#include "../include/shelf.h"
#include "../include/auth.h"
#include "../include/db_conn.h"
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
        // creating a obj that interracts with books db using main db handler above.
        shelf *books_db = new shelf(main_db);
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
        books_db->rmoBook(test);
        books_db->showShelf();  

        delete test;
        delete creds;
        delete books_db;
        delete main_db;
    }catch(const exception& e){
        cout << "exception accured on main server ,code : " << e.what() << "\n";
    }
    return 0;
}
