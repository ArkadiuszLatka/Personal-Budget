#ifndef USERMANAGER_H
#define USERMANAGER_H



#include <iostream>
#include <vector>
#include<windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "UsersFile.h"
//#include  "MetodyPomocnicze.h"
using namespace std;

class UserManager
{
    UsersFile usersFile;
    int loggedUserId;
    vector <User> users;


    int downloadIdNewUser();
    bool loginExists( string login);

public:
     UserManager(string usersFile): usersFile(usersFile)
     {
        loggedUserId = 0;
        loadUsersFromFile();
     };
    void userRegistration();

     User enterDataNewUser();
    void loadUsersFromFile();
    void userLogin();
    void changeLoggedUserPassword();
    void logoutUser();



    bool isUserLogged();
    int getLoggedUserId();
    void setLoggedUserId(int number);

};
#endif // UZYTKOWNIKMENEDZER_H
