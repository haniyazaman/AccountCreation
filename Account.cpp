#include <iostream>
#include <string>

#include "Account.h"

using namespace std;

static int accountCounter = 1000;

Account::Account(int numberOwners, double amount)
{
    accountNumber = accountCounter;
    numberOwners = numberOwners;
    ownerPtr = new Person[numOwners];
    balance = amount;
    accountCounter++;
    
    
}
Account::~Account()
{
    delete [] ownerPtr;
}
int Account::withdraw(double amount)
{
    if(amount > 0 && amount <= balance)
    {
        return 0;
    }
    if(amount > balance)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}
int Account::deposit(double amount)
{
    if(amount > 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void Account::setOwner(int ind, Person p)
{
  ownerPtr[ind] = p;
}
Person Account::getOwner(int ind) const
{
   return ownerPtr[ind];
}
int Account::getAccountNumber() const
{
    return accountNumber;
}
int Account::getBalance() const
{
    return balance;
}
int Account::getNumOwners() const
{
    return numOwners;
}
