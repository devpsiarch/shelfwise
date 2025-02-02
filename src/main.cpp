#include <iostream>
#include "../include/Book.h"
#include "../include/Shelf.h"
#include "../include/Auth.h"
#include <mariadb/conncpp.hpp>
using namespace std;
using namespace sql;

int main(void) {

    try {
        Driver* driver = mariadb::get_driver_instance();
        Properties properties;
        properties["hostName"]= "127.0.0.1";
        properties["userName"]= "user here!!";
        // should be hidden
        properties["password"]= "pwd here !!!";
        unique_ptr<Connection> conn(driver->connect(properties));
        // This stement is gonne be used by all methodes 
        Statement *stmnt = conn->createStatement();
        PreparedStatement* prep = conn->prepareStatement(AddUserFormat);
        PreparedStatement* prep2 = conn->prepareStatement(FetchUserFormat);
        

        //Auth::InsertUser("example@gmail.com","hashed_very_good",prep);
        if(Auth::FetchUser("test@gmail.com",prep2)){
            cout << "found sir***************\n";
        }
        Auth::DisplayUsers(stmnt);
        
        conn->close();
        delete stmnt;
        delete prep;
        delete prep2;
    }
    catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
