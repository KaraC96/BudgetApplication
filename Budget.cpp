#include "Budget.h"

void Budget::setId(int newId)
{
    id = newId;
}

void Budget::setUserId(int newUserId)
{
    userId = newUserId;
}

void Budget::setDate(string newDate)
{
    date = newDate;
}

void Budget::setItem(string newItem)
{
    item = newItem;
}

void Budget::setAmount(float newAmount)
{
    amount = newAmount;
}

int Budget::getId() const
{
    return id;
}

int Budget::getUserId() const
{
    return userId;
}

string Budget::getDate() const
{
    return date;
}

string Budget::getItem() const
{
    return item;
}

float Budget::getAmount() const
{
    return amount;
}
