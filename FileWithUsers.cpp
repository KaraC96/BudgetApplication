#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user)
{
    if (!xml.Load(getFileName()))
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
    else
    {
        xml.FindElem();
    }

    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("id", user.getId());
    xml.AddElem("name", user.getName());
    xml.AddElem("surname", user.getSurname());
    xml.AddElem("login", user.getLogin());
    xml.AddElem("password", user.getPassword());

    xml.Save(getFileName());
}

void FileWithUsers::saveAllUsersToFile(vector <User> &users)
{
    xml.Load(getFileName());
    xml.FindElem();

    xml.RemoveElem();

    xml.AddElem("Users");
    xml.IntoElem();

    for (auto& user : users)
    {
        xml.AddElem("User");
        xml.IntoElem();
        xml.AddElem("id", user.getId());
        xml.AddElem("name", user.getName());
        xml.AddElem("surname", user.getSurname());
        xml.AddElem("login", user.getLogin());
        xml.AddElem("password", user.getPassword());

        xml.OutOfElem();
    }

    xml.Save(getFileName());
}

vector <User> FileWithUsers::loadUsersFromFile()
{
    vector <User> users;

    xml.Load(getFileName());

    if (xml.IsWellFormed())
    {
        xml.FindElem("Users");
        xml.IntoElem();

        while (xml.FindElem("User"))
        {
            xml.IntoElem();

            User user;

            xml.FindElem("id");
            user.setId(stoi(xml.GetData()));

            xml.FindElem("name");
            user.setName(xml.GetData());

            xml.FindElem("surname");
            user.setSurname(xml.GetData());

            xml.FindElem("login");
            user.setLogin(xml.GetData());

            xml.FindElem("password");
            user.setPassword(xml.GetData());

            users.push_back(user);

            xml.OutOfElem();
        }

        xml.OutOfElem();
    }
    else
    {
        cout << "Nie mozna otworzyc pliku " << getFileName() << endl;
    }

    return users;
}
