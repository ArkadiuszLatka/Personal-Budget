#include "UserManager.h"


void UserManager::userRegistration()
 {
     User user = enterDataNewUser();

    users.push_back(user);
    usersFile.addUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
 }
User UserManager :: enterDataNewUser()
{
    User user;

    user.setId(downloadIdNewUser());

    string login;
    do
    {
        cout<< "Podaj login: ";
        cin>>login;
        user.setLogin(login);
    } while (loginExists(user.getLogin()) == true);

    string password;
    cout << "Podaj haslo: ";
    cin>>password;
    user.setPassword(password);

    string name;
    cout << "Podaj imie: ";
    cin>>name;
    user.setName(name);

    string surname;
    cout << "Podaj nazwisko: ";
    cin>>surname;
    user.setSurname(surname);

    return user;
}
int UserManager:: downloadIdNewUser()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}
bool UserManager:: loginExists( string login)
{
    for (int i =0;i<users.size();i++)
    {
        if (users[i].getLogin() == login)
        {
        cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }

    }
    return false;

}
/*void UserManager:: wypiszWszystkichUzytkownikow()
{
    for (int i =0;i<users.size();i++)
    {
       cout << users[i].getId() <<endl;
       cout << users[i].getLogin() <<endl;
       cout << users[i].getPassword() <<endl;
    }
}*/
void UserManager::loadUsersFromFile() {
    users = usersFile.loadUsersFromFile();
}

void UserManager::userLogin()
{
    string login = "", password = "";

    cout << "Podaj login: ";
    cin >> login;

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                cin >> password;

                if (itr -> getPassword() == password)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    loggedUserId = itr -> getId();
                    system("pause");
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}
void UserManager::logoutUser()
{
    loggedUserId = 0;
}
void UserManager::changeLoggedUserPassword()
{
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    cin >> newPassword;

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> getId() == loggedUserId)
        {
            itr -> setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    //users.changePasswordInFile(users);
}
bool UserManager::isUserLogged()
{
    if (loggedUserId > 0)
        return true;
    else
        return false;
}
int UserManager::getLoggedUserId()
{
    return loggedUserId;
}
void UserManager::setLoggedUserId(int number)
{
    loggedUserId = number;
}
