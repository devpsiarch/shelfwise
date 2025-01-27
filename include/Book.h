// assures the inclusion of this file once
#pragma once
#include <iostream>
#include <string>
#include <cstdint>
using namespace std;
// Am defining some consts here to regulate and limit the freedome of Book object

class Book {
private:
    // Image Cover;
    // String Author;?
public:
    string Title;
    string Subject;
    string Author;
    uint8_t In_stock;
    Book(string title,string sub,string author,uint8_t stock);
    ~Book();
    
    bool edditTitle(string title);
    bool edditSubject(string sub);
    bool edditAuthor(string author);
    // This methode will be exclusivly for the book manager admin 
    // and will expect the user to be accurate in changing the number of books 
    // in stock , the program has no way to detect if the number is correct or not ,
    // this is your reposnsibility
    void edditStock(uint8_t stock);
    
    void DisplayBookInfo() const;
    bool Equale(Book *book) const;
};
