#include "../include/Book.h"
#include <iostream>
using namespace std;

static const size_t Max_book_title = 100;   
static const size_t Max_book_author = 20;
static const size_t Max_book_subject = 15;
Book::Book(string title,string sub,string author,uint8_t stock){
    Title = title;
    Subject = sub;
    Author = author;
    In_stock = stock;
}
Book::~Book(){
    Title.clear();
}
void Book::DisplayBookInfo() const{
    cout << "Book: " << Title << '\n';
    cout << "we have: " << (int)In_stock << '\n';
}
// This will allow The user to eddit a book 
// when this returns true that means the edditing happended 
// else that means that the edditing did not happen ... suck on this API

bool Book::edditTitle(string title){
    if(title.length() > Max_book_title) return false;
    Title = title;
    return true;
}
bool Book::edditSubject(string sub){
    if(sub.length() > Max_book_subject) return false;
    Subject = sub;
    return true;
}
bool Book::edditAuthor(string author){
    if(author.length() > Max_book_author) return false;
    Author = author;
    return true;
}
void Book::edditStock(uint8_t stock){
    In_stock = stock;
}

bool Book::Equale(Book *book) const {
    if(Title == book->Title && In_stock == book->In_stock) return true;
    else return false;
}
