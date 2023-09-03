#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <ctime>
#include <algorithm>

#include "Budget.h"
#include "ExpenseFile.h"
#include "IncomeFile.h"

struct Income
{
    int incomeId;
    int userId;
    string date;
    string item;
    float amount;
};

class BudgetManager
{
    IncomeFile incomeFile;
    ExpenseFile expenseFile;

    Budget income;
    Budget expense;

    vector <Budget> incomes;
    vector <Budget> expenses;

    const int LOGGED_IN_USER_ID ;

    Budget getNewIncomeData();
    Budget getNewExpenseData();
    int getNewIncomeId();
    int getNewExpenseId();
    float addAmount();
    int convertDateToInt(const string& date);
    void sortIncomes();
    void sortExpenses();

public:

    BudgetManager(string fileNameIncomes, string fileNameExpenses, int loggedInUserId)
    : incomeFile(fileNameIncomes), expenseFile(fileNameExpenses), LOGGED_IN_USER_ID(loggedInUserId)
    {
        expenses = expenseFile.loadExpensesFromFile(LOGGED_IN_USER_ID);
        incomes = incomeFile.loadIncomesFromFile(LOGGED_IN_USER_ID);
    };

    void addIncome();
    void addExpense();
    void balanceSheetThisMonth();
    void balanceSheetPreviousMonth();
    void balanceSheetSelectedPeriod();

};

#endif
