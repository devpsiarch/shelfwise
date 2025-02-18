#include "../include/shelf.h"

using namespace std;
using namespace sql;
// Helper that just reads the file that has the creds
// returns nullptr if not found 
// this expects the file to be in the parent direcotory to this one

// returns a pointer to a shelf instance or nullptr if failed
shelf::shelf(db_conn *inter) {
    handler = inter;
}
shelf::~shelf(){
    handler = nullptr;
}

void shelf::showShelf() const {
    try {
        Statement *stmnt = handler->connect->createStatement();
        ResultSet *res = stmnt->executeQuery(ShowBooksFormat);
        cout << "-------------------Shelf showing-------------------\n";
        while(res->next()){
            cout << "ID: " << res->getInt("id") << '\n'
                << "title: " << res->getString("title") << '\n'
                << "author: " << res->getString("author") << '\n'
                << "isbn: " << res->getString("isbn") << '\n'
                << "lang: " << res->getString("language") << '\n'               
                
                << "pub_year: " << res->getString("publication_year") << '\n'
                << "genre: " << res->getString("genre") << '\n'
                << "publisher: " << res->getString("publisher") << '\n'
                << "pages: " << res->getInt("page_count") << '\n'               
                << "format: " << res->getString("format") << '\n'
                << "stock: " << res->getInt("stock") << '\n'               
                << "-------------------\n";
        }
        cout << "-------------------Shelf showing-------------------\n";
        delete res;
        delete stmnt;
    }
    catch(const exception& e) {
        cerr << "Error while Displaying Books code : " << e.what() << '\n';
    }
}

bool shelf::fetchBook(const string &by_what,const string &index) const {
    try {
        handler->sanitize(by_what);
        handler->sanitize(index);

        PreparedStatement* prep;
        if (by_what == "isbn") {
            prep = handler->connect->prepareStatement(FetchBookByIsbnFormat);
        } else if (by_what == "author") {
            prep = handler->connect->prepareStatement(FetchBookByAuthorFormat);
        } else if (by_what == "publisher") {
            prep = handler->connect->prepareStatement(FetchBookByPubFormat);
        } else if (by_what == "title") {
            prep = handler->connect->prepareStatement(FetchBookByTitleFormat);
        }
        prep->setString(1,index);
        unique_ptr<ResultSet> res(prep->executeQuery()); 
        // now we check the result of the query sent
        if(res->next()){
            if(res->getInt(1) > 0){
                delete prep;
                return true;
            }
        }
        delete prep;
        return false;
    }
    catch(const exception& e){
        cout << "Error while fetching book from books by isbn code : " << e.what() << '\n';
        return false;
    }
}
bool shelf::addBook(book *wanted) const {
   try{
        if(fetchBook("isbn",wanted->getIsbn())){
            cout << "Cant add this book , already exists in database ! (check your isbn) .\n";
            return false;
        }
        // then try to add it to the db 
        PreparedStatement *pstmt = handler->connect->prepareStatement(AddBookFormat); 
        pstmt->setString(1,wanted->getTitle());           // Title
        pstmt->setString(2,wanted->getAuthor());          // Author
        pstmt->setString(3,wanted->getIsbn());            // ISBN
        pstmt->setString(4,wanted->getLanguage());        // Language (ISO 639-1 code)
        pstmt->setInt(5,wanted->getYear());               // Publication Year
        pstmt->setString(6,wanted->getGenre());           // Genre
        pstmt->setString(7,wanted->getPublisher());       // Publisher
        pstmt->setInt(8,wanted->getPages());              // Page Count
        pstmt->setString(9,wanted->getFormat());          // Format
        pstmt->setInt(10,wanted->getStock());             // Stock 
       
        pstmt->executeQuery();
        cout << "Inserted successfully !\n";

        delete pstmt;  
        return true; 
   }catch(const exception& e){
        cout << "Error while adding a book to books code : " << e.what() << '\n';
        return false;
   } 
}
bool shelf::rmoBook(book *wanted) const {
    try {
        if(!fetchBook("isbn",wanted->getIsbn())){
            cout << "No book found with said isbn , check your isbn.\n";
            return false;
        }
        // then try to add it to the db 
        PreparedStatement *pstmt = handler->connect->prepareStatement(DeleteBookByisbnFormat);
        pstmt->setString(1,wanted->getIsbn());           // Title
        pstmt->executeQuery();
        cout << "Deleted successfully !\n";
        delete pstmt; 
        return true;
    }catch(const exception& e){
        cout << "Error removing the book from books code : " << e.what() << '\n';
        return false;
    }
}

bool shelf::editBookStock(const string &isbn_,int new_val){
    try {
        handler->sanitize(isbn_); 
        PreparedStatement *pstmt = handler->connect->prepareStatement(EditBookStock);
        pstmt->setInt(1,new_val);
        pstmt->setString(2,isbn_);
        pstmt->executeQuery();
        cout << "Edited successfully ... \n";
        return true;
    }catch(const exception& e){
        cout << "Error editing a book by isbn ... \n";
        return false;
    }
}
