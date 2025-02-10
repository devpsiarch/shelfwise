#include "Auth.h"
using namespace std;
 
bool Auth::ValidEmail(const string &mail){
    unsigned int i = 0;
    while(i < mail.length()){
        if(mail[i] == '@') break;
        i++;
    }
    if(mail.substr(i,mail.length()-i) == MailFormat){
        return true;
    }
    return false;
}

string Auth::ShaPwd(const string &pwd){
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, pwd.c_str(), pwd.size());
    SHA256_Final(hash, &sha256);

    // Convert binary hash to hex string
    std::string hex_hash;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        char buf[3];
        sprintf(buf, "%02x", hash[i]);
        hex_hash += buf;
    }
    return hex_hash; 
}
