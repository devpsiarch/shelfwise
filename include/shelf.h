#pragma once
#include "book.h"
#include <unordered_map>
#include <iostream>
#include <limits>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <fstream>
#include <mariadb/conncpp.hpp>
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
    Properties creds;
    unique_ptr<Connection> connect;
public:
    // The point from making the object shelf , is that anyone can create a Bundle (Group) of book 
    // depending on a specific relation based on the attributes that the book has .
    // This allows for much more freedom in searching and filtering books
    // The contructor has the jobs : 
    // -> reads a file for creds (unique format dont mess it up).
    // -> gets the properties 
    // -> make the connection to the database
    shelf(vector<string> &data);
    ~shelf();
    // Shows some info about the shelf being used aka the (db)
    void showShelf() const;
    // This gets you the vector do init a shelf instance
    static vector<string>* readCreds(const string filename);
    // checks if a book already exists in the database given its isbn which is unique to each book 
    bool fetchBook(const string &isbn_);
    // duh , adds a book to the db
    bool addBook(book *wanted);
    bool rmoBook(book *wanted);
    // we will have later the option to edit the books if a mistake were to arrise 
    // it needs us to impliment a bunch of methodes that are repeatative to change each attribute 
    // if the db.
};
