#ifndef EXPENSEFILE_H
#define EXPENSEFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Budget.h"
#include "AuxiliaryMethods.h"
#include "TextFile.h"
#include "Markup.h"

class ExpenseFile : public TextFile
{
    CMarkup xml;

    int LastRecipientID;

public:

    ExpenseFile(string fileNameExpenses) : TextFile(fileNameExpenses)
    {
        LastRecipientID = 0;
    };

    vector <Budget> loadExpensesFromFile(int loggedInUserId);

    void addExpenseToFile(Budget expense);
};

#endif
