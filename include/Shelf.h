#pragma once
#include "Book.h"
#include <unordered_map>
#include <string>
#include <iomanip>
class Shelf {
public:
    // We use an unordered_map here instead of a vector for : 
    // * Speed at finding , add , changing the information for each book
    // But we have one condition , each book has a unique Title that connot be used again
    // This is the condition that the users will handle , the program will worn you when you try adding 
    // an already shelfed book
    unordered_map<string,Book*> Bundle;
    bool AddBook(Book *book);
    bool RmoBook(string title);
    void ShowShelf() const;
};
