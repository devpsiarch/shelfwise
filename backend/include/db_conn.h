// The point from this class is to :
// allow the books and users db handlers classes to agregate this for cleaner code 
// thus well use this once since the db requres a connection to the db , well just make one connection
// and use it for both classes.
#pragma once
#include <mariadb/conncpp.hpp>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;
using namespace sql;


class db_conn {
public:
    Properties creds;
    unique_ptr<Connection> connect;
    db_conn(vector<string> &data);
    ~db_conn();
    // This methode will get us the vector of data that will be needed to init the obj.
    static vector<string>* readCreds(const string filename);
    // checks if the string value caontains vulnrubilitites
    void sanitize(const string &val);
};
