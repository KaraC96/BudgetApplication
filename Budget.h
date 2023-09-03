#ifndef BUDGET_H
#define BUDGET_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Budget
{
    int id;
    int userId;
    string date;
    string item;
    float amount;

public:
        Budget(int id = 0, int userId = 0, string date = "", string item = "", float amount = 0)
    {
        this -> id = id;
        this -> userId = userId;
        this -> date = date;
        this -> item = item;
        this -> amount = amount;
    }

    void setId(int newId);
    void setUserId(int newUserId);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(float newAmount);

    int getId() const;
    int getUserId() const;
    string getDate() const;
    string getItem() const;
    float getAmount() const;
};

#endif
