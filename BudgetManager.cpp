#include "BudgetManager.h"

void BudgetManager::addIncome()
{
    cout << endl << "Dodawanie dochodu" << endl;
    cout << "-----------------" << endl << endl;

    Budget income = getNewIncomeData();

    incomes.push_back(income);
    incomeFile.addIncomeToFile(income);

    cout << "Dochod dodano pomyslnie." << endl;
    system("pause");
}

void BudgetManager::addExpense()
{
    cout << "Dodawanie wydatkow" << endl;
    cout << "------------------" << endl << endl;

    Budget expense = getNewExpenseData();

    expenses.push_back(expense);
    expenseFile.addExpenseToFile(expense);

    cout << "Wydatek dodano pomyslnie." << endl;
    system("pause");
}

Budget BudgetManager::getNewIncomeData()
{
    Budget income;
    string formattedDate;

    income.setId(getNewIncomeId());
    income.setUserId(LOGGED_IN_USER_ID);

    char choice;
    bool validChoice = false;

    while (!validChoice)
    {
        cout << "Czy chcesz dodac dochod z dzisiaj? (t/n): ";
        cin >> choice;

        if (choice == 'n' || choice == 'N')
        {
            bool validDate = false;

            while (!validDate)
            {
                string enteredDate;
                cout << "Wpisz date (rrrr-mm-dd): ";
                cin >> enteredDate;

                validDate = AuxiliaryMethods::parseDate(enteredDate, formattedDate);
            }

            income.setDate(formattedDate);
            validChoice = true;
        }
        else if (choice == 't' || choice == 'T')
        {
            formattedDate = AuxiliaryMethods::getTodayDate();

            income.setDate(formattedDate);
            validChoice = true;
        }
        else
        {
            cout << "Wybierz 't' - tak lub 'n' - nie." << endl;
        }
    }

    cout << "Podaj czego dotyczy ten przychod: ";
    string item;
    cin >> item;
    income.setItem(item);

    cout << "Podaj wysokosc przychodu: ";
    float amount = addAmount();
    income.setAmount(amount);

    return income;
}

Budget BudgetManager::getNewExpenseData()
{
    Budget expense;
    string formattedDate;
    bool validChoice = false;

    expense.setId(getNewIncomeId());
    expense.setUserId(LOGGED_IN_USER_ID);

    char choice;

    while (!validChoice)
    {
        cout << "Czy chcesz dodac wydatek z dzisiaj? (t/n): ";
        cin >> choice;

        if (choice == 'n' || choice == 'N')
        {
            bool validDate = false;

            while (!validDate)
            {
                string enteredDate;
                cout << "Wpisz date (rrrr-mm-dd): ";
                cin >> enteredDate;

                validDate = AuxiliaryMethods::parseDate(enteredDate, formattedDate);
            }

            expense.setDate(formattedDate);
            validChoice = true;
        }
        else if (choice == 't' || choice == 'T')
        {
            formattedDate = AuxiliaryMethods::getTodayDate();

            expense.setDate(formattedDate);
            validChoice = true;
        }
        else
        {
            cout << "Wybierz 't' - tak lub 'n' - nie." << endl;
        }
    }

    cout << "Podaj czego dotyczy ten wydatek: ";
    string item;
    cin >> item;
    expense.setItem(item);

    cout << "Podaj wysokosc wydatku: ";
    float amount = addAmount();
    expense.setAmount(amount);

    return expense;
}

int BudgetManager::getNewIncomeId()
{
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getId() + 1;
}

int BudgetManager::getNewExpenseId()
{
    if (expenses.empty() == true)
        return 1;
    else
        return expenses.back().getId() + 1;
}

float BudgetManager::addAmount()
{
    string inputAmount;
    float amount;

    cin >> inputAmount;
    replace(inputAmount.begin(), inputAmount.end(), ',', '.');
    istringstream(inputAmount) >> amount;

    return amount;
}

void BudgetManager::sortIncomes()
{
    sort(incomes.begin(), incomes.end(), [this](const Budget &income1, const Budget &income2)
    {
        int date1 = AuxiliaryMethods::convertDateToInt(income1.getDate());
        int date2 = AuxiliaryMethods::convertDateToInt(income2.getDate());
        return date1 < date2;
    });
}

void BudgetManager::sortExpenses()
{
    sort(incomes.begin(), incomes.end(), [this](const Budget &expense1, const Budget &expense2)
    {
        int date1 = AuxiliaryMethods::convertDateToInt(expense1.getDate());
        int date2 = AuxiliaryMethods::convertDateToInt(expense2.getDate());
        return date1 < date2;
    });
}

void BudgetManager::balanceSheetThisMonth()
{
    time_t currentTime;
    struct tm* localTime;
    time(&currentTime);
    localTime = localtime(&currentTime);
    int currentYear = localTime->tm_year + 1900;
    int currentMonth = localTime->tm_mon + 1;

    sortIncomes();
    sortExpenses();

    float totalIncome = 0.0;
    float totalExpense = 0.0;

    cout << "Przychody w tym miesiacu:" << endl;
    for (const Budget &income : incomes)
    {
        int incomeYear = stoi(income.getDate().substr(0, 4));
        int incomeMonth = stoi(income.getDate().substr(5, 2));

        if (incomeYear == currentYear && incomeMonth == currentMonth)
        {
            cout << "ID: " << income.getId() << endl;
            cout << "Data: " << income.getDate() << endl;
            cout << "Czego dotyczy: " << income.getItem() << endl;
            cout << "Wysokosc: " << income.getAmount() << endl;
            cout << "-----------------------" << endl;

            totalIncome += income.getAmount();
        }
    }

    cout << "Expenses for This Month:" << endl;
    for (const Budget &expense : expenses)
    {
        int expenseYear = stoi(expense.getDate().substr(0, 4));
        int expenseMonth = stoi(expense.getDate().substr(5, 2));

        if (expenseYear == currentYear && expenseMonth == currentMonth)
        {
            cout << "ID: " << expense.getId() << endl;
            cout << "Data: " << expense.getDate() << endl;
            cout << "Czego dotyczy: " << expense.getItem() << endl;
            cout << "Wysokosc: " << expense.getAmount() << endl;
            cout << "-----------------------" << endl;

            totalExpense += expense.getAmount();
        }
    }

    cout << "Suma przychodow w tym miesiacu: " << totalIncome << endl;
    cout << "Suma wydatkow w tym miesiacu: " << totalExpense << endl;
    float balance = totalIncome - totalExpense;
    cout << "Bilans tego miesiaca: " << balance << endl;

    system("pause");
}

void BudgetManager::balanceSheetPreviousMonth()
{
    time_t currentTime;
    struct tm* localTime;
    time(&currentTime);
    localTime = localtime(&currentTime);
    int currentYear = localTime->tm_year + 1900;
    int currentMonth = localTime->tm_mon + 1;

    int previousMonth = currentMonth - 1;
    int previousYear = currentYear;

    if (previousMonth == 0)
    {
        previousMonth = 12;
        previousYear--;
    }

    sortIncomes();
    sortExpenses();

    float totalIncome = 0.0;
    float totalExpense = 0.0;


    cout << "Przychody w poprzednim miesiacu" << endl;
    for (const Budget &income : incomes)
    {
        int incomeYear = stoi(income.getDate().substr(0, 4));
        int incomeMonth = stoi(income.getDate().substr(5, 2));

        if (incomeYear == previousYear && incomeMonth == previousMonth)
        {
            cout << "ID: " << income.getId() << endl;
            cout << "Data: " << income.getDate() << endl;
            cout << "Czego dotyczy: " << income.getItem() << endl;
            cout << "Wartosc: " << income.getAmount() << endl;
            cout << "-----------------------" << endl;

            totalIncome += income.getAmount();
        }
    }

    cout << "Wydatki w poprzenim miesiacu" << endl;
    for (const Budget &expense : expenses)
    {
        int expenseYear = stoi(expense.getDate().substr(0, 4));
        int expenseMonth = stoi(expense.getDate().substr(5, 2));

        if (expenseYear == previousYear && expenseMonth == previousMonth)
        {
            cout << "ID: " << expense.getId() << endl;
            cout << "Data: " << expense.getDate() << endl;
            cout << "Czego dotyczy: " << expense.getItem() << endl;
            cout << "Wartosc: " << expense.getAmount() << endl;
            cout << "-----------------------" << endl;

            totalExpense += expense.getAmount();
        }
    }

    cout << "Suma przychodow w poprzednim miesiacu " << totalIncome << endl;
    cout << "Suma wydatkow w poprzdnim miesiacu: " << totalExpense << endl;
    float balance = totalIncome - totalExpense;
    cout << "Bilans poprzedniego miesiaca: " << balance << endl;

    system("pause");
}

void BudgetManager::balanceSheetSelectedPeriod()
{
    string fromDate, toDate, formattedDate;
    bool validFromDate = false, validToDate = false;

    while (!validFromDate)
    {
        cout << "Wprowadz poczatkowa date (rrrr-mm-dd): ";
        cin >> fromDate;
        validFromDate = AuxiliaryMethods::parseDate(fromDate, formattedDate);
        if (!validFromDate)
        {
            cout << "Nieprawidlowy format daty lub wartosc poza zakresem. Sprobuj ponownie." << endl;
        }
    }

    while (!validToDate)
    {
        cout << "Wprowadz koncowa date (rrrr-mm-dd): ";
        cin >> toDate;
        validToDate = AuxiliaryMethods::parseDate(toDate, formattedDate);
        if (!validToDate)
        {
            cout << "Nieprawidlowy format daty lub wartosc poza zakresem. Sprobuj ponownie." << endl;
        }
    }

    int fromDateInt = AuxiliaryMethods::convertDateToInt(fromDate);
    int toDateInt = AuxiliaryMethods::convertDateToInt(toDate);

    float totalIncome = 0.0;
    float totalExpense = 0.0;

    cout << "Przychody miedzy " << fromDate << " a " << toDate << endl;
    for (const Budget &income : incomes)
    {
        int incomeDateInt = AuxiliaryMethods::convertDateToInt(income.getDate());

        if (incomeDateInt >= fromDateInt && incomeDateInt <= toDateInt)
        {
            cout << "ID: " << income.getId() << endl;
            cout << "Data: " << income.getDate() << endl;
            cout << "Czego dotyczy: " << income.getItem() << endl;
            cout << "Wartosc: " << income.getAmount() << endl;
            cout << "-----------------------" << endl;

            totalIncome += income.getAmount();
        }
    }

    cout << endl << "Wydatki miedzy " << fromDate << " a " << toDate << endl;
    for (const Budget &expense : expenses)
    {
        int expenseDateInt = AuxiliaryMethods::convertDateToInt(expense.getDate());

        if (expenseDateInt >= fromDateInt && expenseDateInt <= toDateInt)
        {
            cout << "ID: " << expense.getId() << endl;
            cout << "Data: " << expense.getDate() << endl;
            cout << "Czego dotyczy: " << expense.getItem() << endl;
            cout << "Wartosc: " << expense.getAmount() << endl;
            cout << "-----------------------" << endl;

            totalExpense += expense.getAmount();
        }
    }

    cout << "Suma przychodow w danym przedziale czasowym: " << totalIncome << endl;
    cout << "Suma wydaktkow w danym przedziale czasowym: " << totalExpense << endl;
    float balance = totalIncome - totalExpense;
    cout << "Bilans w danym przedziale czasowym:: " << balance << endl;

    system("pause");
}
