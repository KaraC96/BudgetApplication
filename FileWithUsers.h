#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "TextFile.h"
#include "Markup.h"

class FileWithUsers : public TextFile
{
    CMarkup xml;
    User getUserData(string UserDataToLineWithDashe);

public:

    FileWithUsers(string fileNameUsers) : TextFile(fileNameUsers){};
    void addUserToFile(User user);

    vector <User> loadUsersFromFile();
    void saveAllUsersToFile(vector <User> &users);
};

#endif
