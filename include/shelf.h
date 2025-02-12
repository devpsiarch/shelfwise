#pragma once
#include "./book.h"
#include "./db_conn.h"
#include <unordered_map>
#include <iostream>
#include <limits>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;
using namespace sql;
// the shelf is basicly a database on its own , it has a connection to a mariadb db and makes quries using the 
// db class defined earlier , this is just to make an intermideate layer between writting quries and receving 
// responses.


// Here i will define some const string that define the interataction between the database and the server 
const string FetchBookByIsbnFormat = "SELECT COUNT(*) FROM shelfwise_db.books WHERE isbn=?";
const string ShowBooksFormat = "SELECT * FROM shelfwise_db.books;";
const string DeleteBookByisbnFormat = "DELETE FROM shelfwise_db.books WHERE isbn=?";
const string AddBookFormat = 
"INSERT INTO shelfwise_db.books (title, author, isbn, language,"
    "publication_year, genre, publisher, page_count,"
    "format, stock) "
    "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

class shelf {
private:
    db_conn *handler;
public:
    // Instead for each class object to make a connection to the database which is annoying
    // each class obj makes has a pointer to one that can be shared by manner db handler objects since
    // we (i mean I) cant make a custom one that handlers all safely.
    shelf(db_conn *inter);
    // The destructor makes the handler pointers points to nullptr instead of closing ... check thi API bro !
    ~shelf();
    // Shows some info about the shelf being used aka the (db)
    void showShelf() const;
    // checks if a book already exists in the database given its isbn which is unique to each book 
    bool fetchBook(const string &isbn_);
    // duh , adds a book to the db
    bool addBook(book *wanted);
    bool rmoBook(book *wanted);
    // we will have later the option to edit the books if a mistake were to arrise 
    // it needs us to impliment a bunch of methodes that are repeatative to change each attribute 
    // if the db.
};
