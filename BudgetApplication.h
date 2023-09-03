#include <iostream>

#include "UserManager.h"
#include "BudgetManager.h"

class BudgetApplication
{
    UserManager userManager;
    BudgetManager *budgetManager;
    const string FILE_NAME_WITH_BUDGET;
    const string FILE_NAME_WITH_INCOMES;

public:
    BudgetApplication(string fileNameUsers, string fileNameIncomes, string fileNameExpenses)
    : userManager(fileNameUsers), FILE_NAME_WITH_BUDGET(fileNameIncomes), FILE_NAME_WITH_INCOMES(fileNameExpenses)
    {
        budgetManager = NULL;
    };
    ~BudgetApplication()
    {
      delete budgetManager;
      budgetManager = NULL;
    };

    void registerUser();
    void loginUser();
    void changePassword();
    void logoutUser();

    bool isUserLoggedIn();
    void addIncome();
    void addExpense();
    void balanceSheetThisMonth();
    void balanceSheetPreviousMonth();
    void balanceSheetSelectedPeriod();

};

