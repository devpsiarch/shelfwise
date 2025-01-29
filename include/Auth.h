#pragma once
#include <string>
#include <openssl/sha.h>
using namespace std;

class Auth {
public:
    static bool ValidEmail(const string mail);
    static string ShaPwd(const string &pwd);
    // THis methode is supposed to look in the database for the email and password that the user submitted
    static void Fetchdb(const string mail,const string pwd);
};
