#include "UserManager.h"

void UserManager::registerUser()
{
    User user = getNewUserData();

    users.push_back(user);
    fileWithUsers.addUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User UserManager::getNewUserData()
{
    User user;
    user.setId(getNewUserId());

    string login = "", password = "", name = "", surname = "";

        cout << endl << "DODAWANIE UZYTKOWNIKA" << endl;

    cout << "Podaj imie: ";
    user.setName(AuxiliaryMethods::loadLine());
    user.setName(AuxiliaryMethods::changeFirstLetterForUpperCaseAndOthersForLowerCase(user.getName()));

    cout << "Podaj nazwisko: ";
    user.setSurname(AuxiliaryMethods::loadLine());
    user.setSurname(AuxiliaryMethods::changeFirstLetterForUpperCaseAndOthersForLowerCase(user.getSurname()));

    do
    {
        cout << "Podaj login: ";
        login = AuxiliaryMethods::loadLine();
        user.setLogin(login);
    }
    while (loginExists(user.getLogin()) == true);

    cout << "Podaj haslo: ";
    password = AuxiliaryMethods::loadLine();
    user.setPassword(password);

    return user;
}

int UserManager::getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::loginExists(string login)
{
    for (size_t i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::loginUser()
{
    string login = "", passsword = "";

    cout << endl << "LOGOWANIE UZYTKOWNIKA" << endl;
    cout << endl << "Podaj login: ";
    login = AuxiliaryMethods::loadLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int attemptsNumber = 3; attemptsNumber > 0; attemptsNumber--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << attemptsNumber << ": ";
                passsword = AuxiliaryMethods::loadLine();

                if (itr -> getPassword() == passsword)
                {
                    loggedInUserId = itr -> getId();
                    cout << endl << "Zalogowales sie." << endl << endl;
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

void UserManager::changePassword(int loggedInUserId)
{
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = AuxiliaryMethods::loadLine();

    for (auto& user : users)
    {
        if (user.getId() == loggedInUserId)
        {
            user.setPassword(newPassword);
            break;
        }
    }

    cout << "Haslo zostalo zmienione pomyslnie" << endl;
    fileWithUsers.saveAllUsersToFile(users);
}

void UserManager::logoutUser()
{
    if (loggedInUserId == 0)
        cout << "Nikt nie jest zalogowany" << endl;
    else {
        vector <User>::iterator itr = users.begin();
        while (itr != users.end())
        {
            if (itr -> getId() == loggedInUserId)
                break;
            itr++;
        }
        cout << "Uzytkownik: " << itr -> getLogin() << ", wylogowany." << endl;
        loggedInUserId = 0;
    }
}

int UserManager::getLoggedInUserId()
{
    return loggedInUserId;
}

bool UserManager::isUserLoggedIn()
{
    if (loggedInUserId > 0)
        return true;
    else {
        return false;
    }
}
