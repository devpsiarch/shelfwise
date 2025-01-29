#include <iostream>
#include "../include/Book.h"
#include "../include/Shelf.h"
#include "../include/Auth.h"
using namespace std;

int main(void) {
    Shelf test = Shelf("Stories");
    test.AddBook(new Book("Niggers running","Slavery","Memyselfandi",5));
    test.AddBook(new Book("slaves booking it","Slavery","Memyselfandi",4));
    test.AddBook(new Book("The Silent Patient","Slavery","Memyselfandi", 5));
    test.AddBook(new Book("Gone Girl","Slavery","Memyselfandi", 3));
    test.AddBook(new Book("The Girl on the Train","Slavery","Memyselfandi", 7));
    test.AddBook(new Book("Sharp Objects","Slavery","Memyselfandi", 2));
    test.AddBook(new Book("Behind Closed Doors","Slavery","Memyselfandi", 10));
    test.RmoBook("Behind Closed Doors");
    ///test.RmoBook("Niggers running");
    test.ShowShelf();
    test.UpdateBook("Niggers running");
    test.ShowShelf();
    return 0;
}
