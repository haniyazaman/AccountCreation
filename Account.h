#pragma once

using namespace std;

struct Date
{
    int month;
    int day;
    int year;
};

struct Person
{
    string name;
    Date DOB;
    string address;
};

class Account
{
private:
   int accountNumber;
   int numOwners;
   Person * ownerPtr;
   double balance;
   int accountCounter;
public: 
    Account(int, double);
    ~Account();
    int withdraw(double);
    int deposit(double);
    void setOwner(int, Person);
    Person getOwner(int) const;
    int getAccountNumber() const;
    int getBalance() const;
    int getNumOwners() const;
};
