#include "../include/db.h"

// request a select all from the users database
// only used by backend server
void db::DisplayUsers(Statement* stmnt){
    try {
        ResultSet *res = stmnt->executeQuery(ShowUsersFormat);
        cout << "-------------------\n";
        // Example of the table from the database
        // --> petition to make it even more abstract
        while(res->next()){
            cout << "ID: " << res->getInt("id") << '\n'
                << "mail: " << res->getString("school_email") << '\n'
                << "password_hashed: " << res->getString("password_hashed") << '\n'
                << "-------------------\n";
        }
        delete res;
    }
    catch(const exception& e) {
        cerr << "Error while Displaying Users: " << e.what() << endl;
    }
}
// The function exepect the mail and password that you passed are correct anc checked
// for example the school mail
// the user may send a request to add a user (themselves) and get a done / failed response
void db::InsertUser(const string &mail,const string &password_hashed,PreparedStatement* prep){
    try {
        prep->setString(1,mail);
        prep->setString(2,password_hashed);
        prep->executeUpdate();
    }
    catch(const exception& e){
        cout << "Error while adding a User to the database: " << e.what() << "\n";
    }
}

// Users can delete themselves as in adding and get a simular reponse
void db::DeleteUser(const string &mail,PreparedStatement* prep){
    try {
        prep->setString(1,mail);
        prep->executeUpdate();
    }
    catch(const exception& e){
        cout << "Error while deleting user from that database: " << e.what() << '\n';
    }
}

// for authentication (loging in)
bool db::FetchUser(const string &mail,PreparedStatement* prep){
    try {
        prep->setString(1,mail);
        unique_ptr<ResultSet> res(prep->executeQuery()); 
        // now we check the result of the query sent
        if(res->next()){
            if(res->getInt(1) > 0){
                return true;
            }
            else return false;
        }
        else return false;
    }
    catch(const exception& e){
        cout << "Error while fetching user mail: " << e.what() << '\n';
        return false;
    }
}
