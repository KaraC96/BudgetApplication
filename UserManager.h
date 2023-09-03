#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "FileWithUsers.h"

class UserManager
{
    int loggedInUserId ;

    vector <User> users;
    FileWithUsers fileWithUsers;

    User getNewUserData();
    int getNewUserId();
    bool loginExists(string login);

public:

    UserManager(string fileNameUsers) : fileWithUsers(fileNameUsers)
    {
        loggedInUserId  = 0;
        users = fileWithUsers.loadUsersFromFile();
    };

    void registerUser();
    void loginUser();
    void changePassword(int loggedInUserId);
    void logoutUser();

    bool isUserLoggedIn();
    int getLoggedInUserId();

};

#endif
