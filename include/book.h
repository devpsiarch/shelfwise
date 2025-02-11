#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
// The point of this classes existance is to make the some intermidatiate process much neeter and easier to
// handle before being eventuay send and stored in the database , for example these objects are used to store 
// new books that we have the intnetion to add to perminantly or the books info read from a different source
// and now are waiting to be handled.
class book {
// each of these data attributes have some conditions that they have to meet to be accepted as 
// a BOOK intermidiate object , to ensure they correspond to the database types. 
private:
    string title;
    string author;
    string isbn;
    string language;
    int year;
    string genre;
    string publisher;
    int pages;
    string format;
    int stock;
public:
    book(const string& t, const string& a, const string& i, const string& lang,
         int y, const string& g, const string& p, int pg, const string& f, int s);
    // is is much better i think to return a immutable ref to the data instead if copying it
    const string& getIsbn() const;
    const string& getTitle() const;
    const string& getAuthor() const;
    const string& getLanguage() const;
    const string& getGenre() const;
    const string& getPublisher() const;
    const string& getFormat() const;
    // come on its only 4 bytes ...
    int getYear() const;
    int getPages() const;
    int getStock() const;
    
    void print() const;
    ~book();
};
// since i know this type is absulotly disgusting 
// here is a template you migt wanna use to create 
// book objects faster :
/* book *test = new book(
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
);*/
// Yourwelcome.
