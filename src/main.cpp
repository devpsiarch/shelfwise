#include <iostream>
#include "../include/Book.h"
#include "../include/Shelf.h"
#include "../include/Auth.h"
#include <mariadb/conncpp.hpp>
using namespace std;
using namespace sql;

int main(void) {
    Driver* driver = mariadb::get_driver_instance();
    Properties properties;
    properties["hostName"]= "127.0.0.1";
    properties["userName"]= "user";
    // should be hidden
    properties["password"]= "pwd";
    try {
        unique_ptr<Connection> conn(driver->connect(properties));
        
        Statement *stmnt = conn->createStatement();
        ResultSet *res = stmnt->executeQuery("SELECT * FROM login_shelfwise.users;");
       
        while(res->next()){
            cout << "ID: " << res->getInt("id") << '\n'
                << "mail: " << res->getString("school_email") << '\n'
                << "password_hashed: " << res->getString("password_hashed") << '\n';
        }

        conn->close();
        delete stmnt;
        delete res;
    }
    catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
