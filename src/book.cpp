#include "../include/book.h"
#include <iostream>
using namespace std;


book::book(const string& t, const string& a, const string& i, const string& lang,
     int y, const string& g, const string& p, int pg, const string& f, int s)
     : title(t), author(a), isbn(i), language(lang), year(y),
       genre(g), publisher(p), pages(pg), format(f), stock(s)
{
    // We will go over some conditions that assert that the data that we provided 
    // are compatible with the datatypes that the db hosts
    if(title.length() > 255) {
        throw invalid_argument("Cant have that long of a title.\n");
    }
    if(author.length() > 255) {
        throw invalid_argument("Cant have that long of an author.\n");
    }
    // isbn have to be exacly 17 chars long
    if(isbn.length() != 17) {
        throw invalid_argument("Cant have that long of an author.\n");
    }
    // langs have to be exacly 2 chars long as well
    if(language.length() != 2) {
        throw invalid_argument("Cant have that long of an author.\n");
    }
    if(genre.length() > 100){
        throw invalid_argument("Cant have that big of genre.\n");
    }
    if(publisher.length() > 100){
        throw invalid_argument("Cant have that big of publisher name.\n");
    }
    if(format.length() > 20){
        throw invalid_argument("Cant have that big of publisher name.\n");
    }
    if (year <= 0) {
        throw invalid_argument("Year must be a positive number.`\n");
    }
    if (pages <= 0) {
        throw invalid_argument("Pages must be greater than zero.\n");
    }
    if(stock < 0){
        throw invalid_argument("You cant have negtives in stock.\n");
    }
}
void book::print() const {
    cout << "Title: " << title << "\n"
         << "Author: " << author << "\n"
         << "ISBN: " << isbn << "\n"
         << "Language: " << language << "\n"
         << "Year: " << year << "\n"
         << "Genre: " << genre << "\n"
         << "Publisher: " << publisher << "\n"
         << "Pages: " << pages << "\n"
         << "Format: " << format << "\n"
         << "Stock: " << stock << "\n";
}
const string& book::getTitle() const{
    return title;
}
const string& book::getAuthor() const{
    return author;
}
const string& book::getIsbn() const{
    return isbn;
}
const string& book::getLanguage() const {
    return language;
}

const string& book::getGenre() const {
    return genre;
}

const string& book::getPublisher() const {
    return publisher;
}

const string& book::getFormat() const {
    return format;
}

// Integer-based getters (return int)
int book::getYear() const {
    return year;
}

int book::getPages() const {
    return pages;
}

int book::getStock() const {
    return stock;
}
book::~book(){
}
