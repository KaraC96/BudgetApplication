#include <iostream>

#include "BudgetApplication.h"
#include "Markup.h"

using namespace std;

char selectOptionFromMainMenu();
char selectOptionFromUserMenu();

int main()
{
    BudgetApplication budgetApplication("Users.xml", "Incomes.xml", "Expense.xml");


    char choice;

    while (true)
    {
        if (!budgetApplication.isUserLoggedIn())
        {
            choice =  selectOptionFromMainMenu();

            switch (choice)
            {
            case '1':
                budgetApplication.registerUser();
                break;
            case '2':
               budgetApplication.loginUser();
              break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = selectOptionFromUserMenu();

            switch (choice)
            {
            case '1':
                budgetApplication.addIncome();
                break;
            case '2':
                budgetApplication.addExpense();
                break;
            case '3':
                budgetApplication.balanceSheetThisMonth();
                break;
            case '4':
                budgetApplication.balanceSheetPreviousMonth();
                break;
            case '5':
                budgetApplication.balanceSheetSelectedPeriod();
                break;
            case '9':
                budgetApplication.changePassword();
                break;
            case '0':
                budgetApplication.logoutUser();
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}

char selectOptionFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: " ;

    choice = AuxiliaryMethods::loadChar();

    return choice;
}

char selectOptionFromUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "9. Zmien haslo" << endl;
    cout << "0. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";

    choice = AuxiliaryMethods::loadChar();

    return choice;
}
