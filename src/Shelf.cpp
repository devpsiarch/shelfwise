#include "../include/Shelf.h"
using namespace std;
// Again , a bool indicates of the operation was done successfully ... suck on this API
Shelf::Shelf(string name) {
    Category = name;
}
Shelf::~Shelf(){
    Category.clear();
}
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

bool Shelf::UpdateBook(string title){
    if(Bundle[title] != nullptr){
        // I think this is supposed to be a GUI feature
        // for now its a CLI
        string buffer;
        Book *updated = Bundle[title];
        cout << "("<< updated->Title<<")"<< "What would you like to update: ";
        cin >> buffer;
        cout << '\n';
        if(buffer == "Subject"){
            cout << "updated Subject: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin,buffer);
            return updated->edditSubject(buffer);
        }
        else if(buffer == "Author"){
            cout << "updated Author: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin,buffer);
            return updated->edditAuthor(buffer);
        }
        else if(buffer == "Title"){
            cout << "updated Title: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin,buffer);
            return updated->edditTitle(buffer);
        }
        else if(buffer == "Stock"){
            cout << "updated stock: ";
            int newsize;
            cin >> newsize;
            updated->edditStock((int8_t)newsize);
        }
        else {
            cout << "Unknown attibute ... check your typing or capitilize the first letter \n";
            return false;
        }
    }
    cout << "The book that you are trying to update does not exist ...\n";
    return false;
}

void Shelf::ShowShelf() const {
    // We can add more stuff here as the attibutes of Book grows
    const int titleWidth = 30;
    const int subWidth = 10;
    const int authWidth = 19;
    const int stockWidth =  5;
    const int sumWidth = titleWidth+subWidth+authWidth+stockWidth;
    // Printing the name of the Bundle
    cout << setfill('-') 
        << setw(sumWidth) << "" 
        << '\n';
    cout << setfill(' '); // Reset fill character
    cout << setw(sumWidth/2) << Category << '\n';
    cout << setfill('-') 
        << setw(sumWidth) << "" 
        << '\n';
    cout << setfill(' '); // Reset fill character
    // Printing the Table head
    cout << left 
        << setw(titleWidth) << "TITLE" 
        << setw(subWidth) << "Subject" 
        << setw(authWidth) << "Author"   
        << setw(stockWidth) << "STOCK" 
    << '\n';
    // Printing the line seperator
    cout << setfill('-') 
        << setw(sumWidth) << "" 
        << '\n';
    cout << setfill(' '); // Reset fill character
    // Printing the accual book that are on the Shelf
    for (const auto& pair:Bundle) {
        // In case we pass though a deleted book ,
        // IDK how unordered_map stores the strings in this case
        if(pair.second == nullptr) continue;
        cout << left 
                  << std::setw(titleWidth) << pair.second->Title 
                  << std::setw(subWidth) << pair.second->Subject
                  << std::setw(authWidth) << pair.second->Author
                  << std::setw(stockWidth) << (int)pair.second->In_stock
                  << '\n';
    }
}
