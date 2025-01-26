#include "../include/Book.h"
#include <iostream>
using namespace std;

static const size_t Max_book_name = 100;   

Book::Book(string title,uint8_t stock){
    Title = title;
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
bool Book::EdditBook(string new_title,uint8_t new_stock){
    if(new_title.length() > Max_book_name) return false;
    Title = new_title;
    In_stock = new_stock;
    return true;
}
bool Book::Equale(Book *book) const {
    if(Title == book->Title && In_stock == book->In_stock) return true;
    else return false;
}
