#include "../include/Shelf.h"
using namespace std;
// Again , a bool indicates of the operation was done successfully ... suck on this API
bool Shelf::AddBook(Book *book) {
    if(Bundle[book->Title] != nullptr){
        cout << "The book already exists, Remember , each book has a unique Title\n";
        return false;
    }
    else{
        Bundle[book->Title] = book;
        return true;
    }
}
bool Shelf::RmoBook(string title) {
    if(Bundle[title] != nullptr){
        Book *bookptr = Bundle[title];
        delete bookptr;
        Bundle[title] = nullptr;
        return true;
    }else{
        cout << "The book that you are trying to delete does not exist ...\n";
        return false;
    }
}

void Shelf::ShowShelf() const {
    // We can add more stuff here as the attibutes of Book grows
    const int titleWidth = 30;
    const int stockWidth =  5;
    // Printing the Table head
    cout << left 
          << setw(titleWidth) << "TITLE" 
          << setw(stockWidth) << "STOCK" 
          << '\n';
    // Printing the line seperator
    cout << setfill('-') 
              << setw(titleWidth + stockWidth) << "" 
              << '\n';
    cout << setfill(' '); // Reset fill character
    // Printing the accual book that are on the Shelf
    for (const auto& pair:Bundle) {
        // In case we pass though a deleted book ,
        // IDK how unordered_map stores the strings in this case
        if(pair.second == nullptr) continue;
        cout << left 
                  << std::setw(titleWidth) << pair.second->Title 
                  << std::setw(stockWidth) << (int)pair.second->In_stock
                  << '\n';
    }
}
