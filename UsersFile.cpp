#include "UsersFile.h"

void UsersFile::addUserToFile(User user) {
    CMarkup xml;
    xml.Load(USERS_FILENAME);
    xml.AddElem( "USER" );
    xml.IntoElem();
    {
        xml.AddElem( "ID", user.getId() );
        xml.AddElem( "LOGIN", user.getLogin() );
        xml.AddElem( "PASSWORD", user.getPassword() );
        xml.AddElem( "NAME", user.getName() );
        xml.AddElem( "SURNAME", user.getSurname() );
    }
    xml.OutOfElem();
    xml.Save(USERS_FILENAME);
}
void UsersFile::addAllUsersToFile(vector <User> &users) {
    CMarkup xml;
    xml.AddElem( "USER" );
    xml.IntoElem();
    xml.FindElem();
    xml.IntoElem();
    vector <User>::iterator itrEnd = --users.end();
    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        xml.AddElem( "ID", itr ->getId() );
        xml.AddElem( "LOGIN", itr ->getLogin() );
        xml.AddElem( "PASSWORD",itr ->getPassword() );
        xml.AddElem( "NAME", itr ->getName() );
        xml.AddElem( "SURNAME", itr ->getSurname() );
        xml.Save(USERS_FILENAME );
    }
}
vector<User> UsersFile::loadUsersFromFile() {
    vector<User> users;
    CMarkup xml;
    xml.Load(USERS_FILENAME);
    while (xml.FindElem("USER")) {
        User user;
        xml.IntoElem();
        xml.FindElem("ID");
        user.setId(atoi(MCD_2PCSZ(xml.GetData())));
        xml.FindElem("LOGIN");
        user.setLogin(xml.GetData());
        xml.FindElem("PASSWORD");
        user.setPassword(xml.GetData());
        xml.FindElem("NAME");
        user.setName(xml.GetData());
        xml.FindElem("SURNAME");
        user.setSurname(xml.GetData());
        xml.OutOfElem();
        users.push_back(user);
    }
    return users;
}
