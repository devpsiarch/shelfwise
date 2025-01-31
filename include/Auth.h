#pragma once
#include <openssl/sha.h>
#include <soci/soci.h>
#include <exception>
#include <string>



using namespace std;

class Auth {
public:
    static bool ValidEmail(const string &mail);
    static string ShaPwd(const string &pwd);
    // I will put the methodes that "DEV" can do : dev is the the admin that admits users to the app
    static void DisplayUsers();
    static bool InsertUser(const string &mail,const string &password_hashed);
    static bool DeleteUser(const string &mail,const string &password_hashed);
    // This methode is supposed to look in the database for the email and password that the user submitted
    static bool FetchUser(const string &mail,const string &password_hashed);
    // Methodes for the users convinience should be added later : 
    // -> change password
};
