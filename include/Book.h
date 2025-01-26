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
    uint8_t In_stock;
    Book(string title,uint8_t stock);
    ~Book();
    bool EdditBook(string title,uint8_t stock);
    void DisplayBookInfo() const;
    bool Equale(Book *book) const;
};
