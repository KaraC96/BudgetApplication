#include "BudgetApplication.h"

void BudgetApplication::registerUser()
{
    userManager.registerUser();
}

void BudgetApplication::loginUser()
{
    userManager.loginUser();
    if (userManager.isUserLoggedIn())
    {
        budgetManager = new BudgetManager(FILE_NAME_WITH_BUDGET, FILE_NAME_WITH_INCOMES, userManager.getLoggedInUserId());
    }
}

bool BudgetApplication::isUserLoggedIn()
{
    return userManager.isUserLoggedIn();
}

void BudgetApplication::changePassword()
{
    userManager.changePassword(userManager.getLoggedInUserId());
}

void BudgetApplication::logoutUser()
{
    userManager.logoutUser();
    delete budgetManager;
    budgetManager = NULL;
}

void BudgetApplication::addIncome()
{
    budgetManager -> addIncome();
}

void BudgetApplication::addExpense()
{
    budgetManager -> addExpense();
}

void BudgetApplication::balanceSheetThisMonth()
{
    budgetManager -> balanceSheetThisMonth();
}

void BudgetApplication::balanceSheetPreviousMonth()
{
    budgetManager -> balanceSheetPreviousMonth();
}

void BudgetApplication::balanceSheetSelectedPeriod()
{
    return budgetManager -> balanceSheetSelectedPeriod();
}
