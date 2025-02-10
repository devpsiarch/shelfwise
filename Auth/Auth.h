#pragma once
#include <openssl/sha.h>
#include <exception>
#include <string>
#include <iostream>
#include <format>

using namespace std;

const string MailFormat = "@ensia.edu.dz";

class Auth {
public:
    static bool ValidEmail(const string &mail);
    static string ShaPwd(const string &pwd);
};
