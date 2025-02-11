#include "../include/shelf.h"

using namespace std;
using namespace sql;
// Helper that just reads the file that has the creds
// returns nullptr if not found 
// this expects the file to be in the parent direcotory to this one

// returns a pointer to a shelf instance or nullptr if failed
shelf::shelf(vector<string> &data) {
    Driver* driver = mariadb::get_driver_instance();
    // filling the shelfs data
    creds["hostName"]= data[0];
    creds["userName"]= data[1];
    creds["password"]= data[2];

    connect = unique_ptr<Connection>(driver->connect(creds));
}
shelf::~shelf(){
    connect->close();
}

void shelf::showShelf() const {
    try {
        Statement *stmnt = connect->createStatement();
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

vector<string>* shelf::readCreds(const string filename){
    ifstream file(filename);
    if(!file.is_open()){
        // This will be checked by the caller
        return nullptr;
    }
    string buffer;
    int pres = 0; 
    vector<string> *data = new vector<string>();
    while(getline(file,buffer)){
        // Check for absurd data sizes 
        if(buffer.length() >= 100){
            delete data;
            return nullptr;
        }
        data->push_back(buffer);
        pres ++;
    }
    if(pres > 3 || pres < 3){
        delete data;
        return nullptr;
    }
    return data;
}

bool shelf::fetchBook(const string &isbn_){
    try {
        PreparedStatement* prep = connect->prepareStatement(FetchBookByIsbnFormat);
        prep->setString(1,isbn_);
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
bool shelf::addBook(book *wanted) {
   try{
        if(fetchBook(wanted->getIsbn())){
            cout << "Cant add this book , already exists in database ! (check your isbn) .\n";
            return false;
        }
        // then try to add it to the db 
        PreparedStatement *pstmt = connect->prepareStatement(AddBookFormat); 
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
bool shelf::rmoBook(book *wanted) {
    try {
         if(!fetchBook(wanted->getIsbn())){
            cout << "No book found with said isbn , check your isbn.\n";
            return false;
        }
        // then try to add it to the db 
        PreparedStatement *pstmt = connect->prepareStatement(DeleteBookByisbnFormat);
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
