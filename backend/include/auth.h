#pragma once
#include <openssl/sha.h>
#include "./db_conn.h"
#include <exception>
#include <string>
#include <iostream>
#include <format>

using namespace std;
using namespace sql;

const string AddUserFormat = 
            "INSERT INTO shelfwise_db.users (school_email, password_hashed) "
            "VALUES (?, ?)";

const string DeleteUserFormat = "DELETE FROM shelfwise_db.users WHERE school_email=?";
const string FetchUserFormat = "SELECT COUNT(*) FROM shelfwise_db.users WHERE school_email=?";
const string ShowUsersFormat = "SELECT * FROM shelfwise_db.users;";
// to restrict only a seclection of users to use the service.
const string MailFormat = "@gmail.com";

class auth {
private:
    db_conn *handler;
public:
    // The same as the books db handler.
    auth(db_conn *inter);
    // The destructor makes the handler pointers points to nullptr instead of closing ... check thi API bro !
    ~auth();
    // from herer on out , we only have feature methodes that are easy to use or create new ones.
    
    // These are some validation methodes , more will be added later is neccesary.
    static bool ValidEmail(const string &mail);
    static string ShaPwd(const string &pwd);
    // I will put the methodes that "DEV" can do : dev is the the admin that admits users to the app
    // Most of these methodes exepect from the calling function to : 
    // -> prepare and validate the data being added (fromat etc...)
    // -> to be given a pointer to a statement (conncpp uses) to execute the quries
    
    // this assumes that the db has a id as int , then the rest of the attributes are strings which 
    // works in this case
    // am trying to memic the same API acros the other objects to make it untiuitive to use ...
    // hell yea dude ...
    void showUsers() const;
    // The add user methode may cause problems later on if mode attributes are added ...
    // if i was me (which i am) idd make another intermediate object to integrate the addition of new 
    // users ... just like in the books db.
    bool addUser(const string &mail,const string &password_hashed);
    bool rmoUser(const string &mail);
    // This methode is supposed to look in the database for the email and password that the user submitted
    bool fetchUser(const string &mail);
    // Methodes for the users convinience should be added later : 
    // -> change password
};
