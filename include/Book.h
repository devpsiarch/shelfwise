#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
// The point of this classes existance is to make the some intermidatiate process much neeter and easier to
// handle before being eventuay send and stored in the database , for example these objects are used to store 
// new books that we have the intnetion to add to perminantly or the books info read from a different source
// and now are waiting to be handled.
class Book {
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
    Book(const string& t, const string& a, const string& i, const string& lang,
         int y, const string& g, const string& p, int pg, const string& f, int s);
    ~Book();
};
