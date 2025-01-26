#include <iostream>
#include "../include/Book.h"
#include "../include/Shelf.h"
using namespace std;

int main(void) {
    Shelf test = Shelf();
    test.AddBook(new Book("Niggers running",5));
    test.AddBook(new Book("slaves booking it",4));
    test.AddBook(new Book("The Silent Patient", 5));
    test.AddBook(new Book("Gone Girl", 3));
    test.AddBook(new Book("The Girl on the Train", 7));
    test.AddBook(new Book("Sharp Objects", 2));
    test.AddBook(new Book("Behind Closed Doors", 10));
    test.RmoBook("Behind Closed Doors");
    test.RmoBook("Niggers running");
    test.ShowShelf();
    return 0;
}
