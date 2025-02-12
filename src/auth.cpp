#include "../include/auth.h"
bool auth::ValidEmail(const string &mail){
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

string auth::ShaPwd(const string &pwd){
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
auth::auth(db_conn *inter) {
    handler = inter;
}
auth::~auth(){
    handler = nullptr;
}

// request a select all from the users database
// only used by backend server
void auth::showUsers() const {
    try {
        Statement *stmnt = handler->connect->createStatement();
        ResultSet *res = stmnt->executeQuery(ShowUsersFormat);
        cout << "---------------------All Users---------------------\n";
        while(res->next()){
            cout << "ID: " << res->getInt("id") << '\n'
                << "mail: " << res->getString("school_email") << '\n'
                << "password_hashed: " << res->getString("password_hashed") << '\n'
                << "-------------------\n";
        }
        cout << "---------------------All Users---------------------\n";
        delete res;
        delete stmnt;
    }
    catch(const exception& e) {
        cerr << "Error while Displaying users code : " << e.what() << '\n';
    }
}

bool auth::addUser(const string &mail,const string &password_hashed){
   try{
        if(fetchUser(mail)){
            cout << "Cant add this user , already exists in database !\n";
            return false;
        }
        // then try to add it to the db 
        PreparedStatement *pstmt = handler->connect->prepareStatement(AddUserFormat); 
        pstmt->setString(1,mail);           // Title
        pstmt->setString(2,password_hashed);// Author

       
        pstmt->executeQuery();
        cout << "Inserted successfully !\n";

        delete pstmt;  
        return true; 
   }catch(const exception& e){
        cout << "Error while adding a user to users ,code : " << e.what() << '\n';
        return false;
   }
}

// Users can delete themselves as in adding and get a simular reponse
bool auth::rmoUser(const string &mail){
    try {
         if(!fetchUser(mail)){
            cout << "No user found with said mail.\n";
            return false;
        }
        // then try to add it to the db 
        PreparedStatement *pstmt = handler->connect->prepareStatement(DeleteUserFormat);
        pstmt->setString(1,mail);           // Title
        pstmt->executeQuery();
        cout << "Deleted successfully !\n";
        delete pstmt; 
        return true;
    }catch(const exception& e){
        cout << "Error removing the user from users code : " << e.what() << '\n';
        return false;
    }
}

bool auth::fetchUser(const string &mail){
    try {
        PreparedStatement* prep = handler->connect->prepareStatement(FetchUserFormat);
        prep->setString(1,mail);
        unique_ptr<ResultSet> res(prep->executeQuery()); 
        // now we check the result of the query sent
        if(res->next()){
            if(res->getInt(1) > 0){
                delete prep;
                return true;
            }
        }
        delete prep;
        return false;
    }
    catch(const exception& e){
        cout << "Error while fetching user from users by mail ,code : " << e.what() << '\n';
        return false;
    }
}
