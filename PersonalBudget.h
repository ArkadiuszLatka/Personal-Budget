#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include <windows.h>


#include "UserManager.h"
#include "AuxiliaryMethods.h"
#include "User.h"

using namespace std;

class PersonalBudget {

    UserManager userManager;


public:
    PersonalBudget (string usersFilename )
        : userManager(usersFilename) {

    };
    ~PersonalBudget() {

    }
    int getLoggedUserId();
    void loginMenu();
    void userRegistration();
    void userLogin();
    void logoutUser();
    bool isUserLogged();
    void wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuEdycja();
    void changeLoggedUserPassword();

};
#endif
