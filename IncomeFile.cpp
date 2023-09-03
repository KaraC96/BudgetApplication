#include "IncomeFile.h"

void IncomeFile::addIncomeToFile(Budget income)
{
    if (!xml.Load(getFileName()))
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }
    else
    {
        xml.FindElem();
    }

    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("incomeId", income.getId());
    xml.AddElem("userId", income.getUserId());
    xml.AddElem("date", income.getDate());
    xml.AddElem("item", income.getItem());

    ostringstream amountStr;
    amountStr << fixed << setprecision(2) << income.getAmount();
    xml.AddElem("amount", amountStr.str());

    xml.Save(getFileName());
}

vector <Budget> IncomeFile::loadIncomesFromFile(int loggedInUserId)
{
    vector <Budget> incomes;

    xml.Load(getFileName());

    if (xml.IsWellFormed())
    {
        xml.FindElem("Incomes");
        xml.IntoElem();

        while (xml.FindElem("Income"))
        {
            xml.IntoElem();

            xml.FindElem("incomeId");
            int incomeId = stoi(xml.GetData());

            xml.FindElem("userId");
            int userId = stoi(xml.GetData());

            xml.FindElem("date");
            string date = xml.GetData();

            xml.FindElem("item");
            string item = xml.GetData();

            xml.FindElem("amount");
            float amount = stof(xml.GetData());

            Budget income(incomeId, userId, date, item, amount);
            incomes.push_back(income);

            xml.OutOfElem();
        }

        xml.OutOfElem();
    }
    else
    {
        cout << "Nie mozna otworzyc pliku " << getFileName() << endl;
    }

    return incomes;
}
