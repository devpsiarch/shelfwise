#pragma once
#include "Book.h"
#include <unordered_map>
#include <iostream>
#include <limits>
#include <string>
#include <iomanip>
class Shelf {
public:
    // We use an unordered_map here instead of a vector for : 
    // * Speed at finding , add , changing the information for each book
    // But we have one condition , each book has a unique Title that connot be used again
    // This is the condition that the users will handle , the program will worn you when you try adding 
    // an already shelfed book
public:
    // The point from making the object shelf , is that anyone can create a Bundle (Group) of book 
    // depending on a specific relation based on the attributes that the book has .
    // This allows for much more freedom in searching and filtering books
    // since the Bundle is a relativly light weight object (its just strings pointing to a Books)
    unordered_map<string,Book*> Bundle; 
    string Category; 
    Shelf(string name);
    ~Shelf();
    bool AddBook(Book *book);
    bool RmoBook(string title);
    bool UpdateBook(string title);
    void ShowShelf() const;
};
