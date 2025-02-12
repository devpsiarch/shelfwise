#include "../include/db_conn.h"
using namespace std;
using namespace sql;

db_conn::db_conn(vector<string> &data) {
    Driver* driver = mariadb::get_driver_instance();
    // filling the shelfs data
    creds["hostName"]= data[0];
    creds["userName"]= data[1];
    creds["password"]= data[2];

    connect = unique_ptr<Connection>(driver->connect(creds));
}
db_conn::~db_conn(){
    connect->close();
}
vector<string>* db_conn::readCreds(const string filename){
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
