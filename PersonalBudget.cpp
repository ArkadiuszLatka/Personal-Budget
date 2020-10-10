#include "PersonalBudget.h"



int PersonalBudget::getLoggedUserId(){
    return userManager.getLoggedUserId();
}
bool PersonalBudget::isUserLogged()
{
    userManager.isUserLogged();
}
 void PersonalBudget::userRegistration()
 {
     userManager.userRegistration();
 }

void PersonalBudget::userLogin() {
    userManager.userLogin();

}

void PersonalBudget::changeLoggedUserPassword()
{
    userManager.changeLoggedUserPassword();
}

void PersonalBudget::logoutUser()
{
    userManager.logoutUser();

}





