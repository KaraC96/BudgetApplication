#ifndef INCOMEFILE_H
#define INCOMEFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Budget.h"
#include "AuxiliaryMethods.h"
#include "TextFile.h"
#include "Markup.h"

class IncomeFile  : public TextFile
{
    CMarkup xml;

    int LastRecipientID;

public:

    IncomeFile (string fileNameIncomes) : TextFile(fileNameIncomes)
    {
        LastRecipientID = 0;
    };

    vector <Budget> loadIncomesFromFile(int loggedInUserId);

    void addIncomeToFile(Budget income);
};

#endif
