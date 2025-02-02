#pragma once
#include <openssl/sha.h>
#include <mariadb/conncpp.hpp>
#include <exception>
#include <string>
#include <iostream>
#include <format>

using namespace std;
using namespace sql;

const string AddUserFormat = 
            "INSERT INTO table (values) "
            "VALUES (?, ?)";

const string DeleteUserFormat = "DELETE FROM table WHERE something=?";
const string FetchUserFormat = "SELECT COUNT(*) FROM table WHERE something=?";
const string ShowUsersFormat = "SELECT * FROM table;";
const string MailFormat = "@x.y";

class Auth {
public:
    static bool ValidEmail(const string &mail);
    static string ShaPwd(const string &pwd);
    // I will put the methodes that "DEV" can do : dev is the the admin that admits users to the app
    // Most of these methodes exepect from the calling function to : 
    // -> prepare and validate the data being added (fromat etc...)
    // -> to be given a pointer to a statement (conncpp uses) to execute the quries
    static void DisplayUsers(Statement* stmnt);
    static void InsertUser(const string &mail,const string &password_hashed,PreparedStatement* prep);
    static void DeleteUser(const string &mail,PreparedStatement* prep);
    // This methode is supposed to look in the database for the email and password that the user submitted
    static bool FetchUser(const string &mail,PreparedStatement* prep);
    // Methodes for the users convinience should be added later : 
    // -> change password
};
