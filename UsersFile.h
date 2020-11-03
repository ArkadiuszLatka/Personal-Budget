#ifndef USERS_H
#define USERS_H

#include <iostream>
#include <vector>
#include "User.h"
#include "Markup.h"

using namespace std;

class UsersFile {
    const string USERS_FILENAME;
public:
    UsersFile(string usersFileName): USERS_FILENAME(usersFileName) {};
    void addUserToFile(User user);
    vector<User> loadUsersFromFile();
    void addAllUsersToFile (vector <User> &users);
};

#endif // USERS_H
