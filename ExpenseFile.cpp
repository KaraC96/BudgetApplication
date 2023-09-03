#include "ExpenseFile.h"

void ExpenseFile::addExpenseToFile(Budget expense)
{
    if (!xml.Load(getFileName()))
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }
    else
    {
        xml.FindElem();
    }

    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("expenseId", expense.getId());
    xml.AddElem("userId", expense.getUserId());
    xml.AddElem("date", expense.getDate());
    xml.AddElem("item", expense.getItem());

    ostringstream amountStr;
    amountStr << fixed << setprecision(2) << expense.getAmount();
    xml.AddElem("amount", amountStr.str());

    xml.Save(getFileName());
}

vector <Budget> ExpenseFile::loadExpensesFromFile(int loggedInUserId)
{
    vector <Budget> expenses;

    xml.Load(getFileName());

    if (xml.IsWellFormed())
    {
        xml.FindElem("Expenses");
        xml.IntoElem();

        while (xml.FindElem("Expense"))
        {
            xml.IntoElem();

            xml.FindElem("expenseId");
            int expenseId = stoi(xml.GetData());

            xml.FindElem("userId");
            int userId = stoi(xml.GetData());

            xml.FindElem("date");
            string date = xml.GetData();

            xml.FindElem("item");
            string item = xml.GetData();

            xml.FindElem("amount");
            float amount = stof(xml.GetData());

            Budget expense(expenseId, userId, date, item, amount);
            expenses.push_back(expense);

            xml.OutOfElem();
        }

           xml.OutOfElem();
    }
    else
    {
        cout << "Nie mozna otworzyc pliku " << getFileName() << endl;
    }

    return expenses;
}
