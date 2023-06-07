/******************************************************************************

This program allows you to crete an account, deposit/withdraw from the account, 
display the contents, delete/add owners to the account and or delete the account

*******************************************************************************/
#include <iostream>
#include <string>
#include <iomanip>
#include "Account.h"


using namespace std;
const int MAX_NUM_ACCOUNTS = 4;
Account * accountArray[MAX_NUM_ACCOUNTS];

int linearSearch(Account**, int, int);
int main()
{
    int MenuChoice;
    int numberOwners;
    int numAccounts = 0; 
    double amount;
    Date temp;
    Person temp2;
    int accountNumber;
    while(true)
    {
    //cout << endl;
    cout << "Menu" << endl;
    cout << "----" << endl;
    cout << "1->Create account 2->Deposit   3->Withdraw     4->Display " << endl;
    cout << "5->Delete owner   6->Add owner 7->Delete accnt 8->Quit    " << endl;
    cin >> MenuChoice;
    if(MenuChoice == 8)
    {
        break;
    }
    
    
    if(MenuChoice == 1)
    {
        //Max number of Accounts reached
        if(numAccounts == MAX_NUM_ACCOUNTS)
        {
            cout << "Max number of accounts reached, cannot add a new account" << endl;
            continue;
        }
        
        cout << "Enter number of owners: ";
        cin >> numberOwners;
        cout << "Enter amount: ";
        cin >> amount;
        cin.clear();
        cin.ignore(10000,'\n');
        Account* act = new Account(numberOwners, amount);
        for(int i =0; i < numberOwners; i++)
        {
            cout << "Enter owner's name: ";
            getline(cin, temp2.name);
            cout << "Enter owner's DOB, month, day then year: ";
            cin >> temp.month >> temp.day >> temp.year;
            cin.clear();
            cin.ignore(10000,'\n');
            temp2.DOB = temp;
            cout << "Enter owner's address: ";
            getline(cin, temp2.address);
            act->setOwner(i, temp2);
        }
        
        accountArray[numAccounts++] = act;
        
        //act->setAccountNumber(100);
        cout << "Account #" << act->getAccountNumber() << " created" << endl;
        //Max number of Accounts reached
        // if(numAccounts == MAX_NUM_ACCOUNTS)
        // {
        //     cout << "Max number of accounts reached, cannot add new account" << endl;
        // }
        
        
    }
    if(MenuChoice == 2)//Deposit
    {
        cout << "Enter account number: ";
        cin >> accountNumber;
        //cout << "Enter amount: ";
        //cin >> amount;
        //check if account exist, linear search
        int searchValue = linearSearch(accountArray, numAccounts, accountNumber);
        //cout << searchValue;
        if(searchValue == -1)
        {
            cout << "No such account" << endl;
        }
        else
        {
            cout << "Enter amount: ";
            cin >> amount;
            if(amount < 0)
            {
                cout << "Amount cannot be negative, deposit not executed" << endl;
                continue;
            }
            cout << setprecision(2) << fixed;
            double newBalance = accountArray[searchValue]->deposit(amount);
            cout << "New balance is $" << accountArray[searchValue]->getBalance() << endl;
        }
        
        
    }
    if(MenuChoice == 3)//Withdraw
    {
        cout << "Enter account number: ";
        cin >> accountNumber;
        //cout << "Enter amount: ";
        //cin >> amount;
        //check if account exist, linear search
        int searchValue = linearSearch(accountArray, numAccounts, accountNumber);
        if(searchValue == -1)
        {
            cout << "No such account" << endl;
        }
        else
        {
            cout << "Enter amount: ";
            cin >> amount;
            if(amount < 0)
            {
                cout << "Amount cannot be negative, withdrawal not executed" << endl;
                
            }
            else if(amount > accountArray[searchValue]->getBalance())
            {
                cout << "Insufficient balance, withdrawal not executed" << endl;
                
            }
            else
            {
            cout << setprecision(2) << fixed;
            double newBalance = accountArray[searchValue]->withdraw(amount);
            //cout << endl;
            cout << "New balance is $" << accountArray[searchValue]->getBalance() << endl;
            }
        }
    }
    if(MenuChoice == 4)
    {
        for(int searchValue = 0; searchValue < numAccounts; searchValue++)
        {
        cout << "Account Number: " <<  accountArray[searchValue]->getAccountNumber() << endl;
        cout << "--------------" << endl;
        //cin >> accountNumber;
        //cout << endl;
        //int searchValue = linearSearch(accountArray, numAccounts, accountNumber);
       for(int i =0; i < accountArray[searchValue]->getNumOwners();i++)
       {
        Person owner = accountArray[searchValue]->getOwner(i);
        //cout << "--------------" << endl;
        cout << "*Name: " << owner.name << ", DOB: " << owner.DOB.month << "/" << owner.DOB.day << "/" << owner.DOB.year << endl;
        cout << "Address: " << owner.address << endl;
        
       }
        cout << setprecision(2) << fixed;
       cout << "*Balance: $" << accountArray[searchValue]->getBalance() << " \n";
    }
    }
    if(MenuChoice == 5)
    {
        continue;
    // cout << "Menu" << endl;
    // cout << "----" << endl;
    // cout << "1->Create account 2->Deposit   3->Withdraw     4->Display" << endl;
    // cout << "5->Delete owner   6->Add owner 7->Delete accnt 8->Quit" << endl;
    // cin >> MenuChoice; 
    }
    if(MenuChoice == 6)
    {
        continue;
    // cout << "Menu" << endl;
    // cout << "----" << endl;
    // cout << "1->Create account 2->Deposit   3->Withdraw     4->Display" << endl;
    // cout << "5->Delete owner   6->Add owner 7->Delete accnt 8->Quit" << endl;
    // cin >> MenuChoice;
    }
    if(MenuChoice == 7)
    {
        continue;
    // cout << "Menu" << endl;
    // cout << "----" << endl;
    // cout << "1->Create account 2->Deposit   3->Withdraw     4->Display" << endl;
    // cout << "5->Delete owner   6->Add owner 7->Delete accnt 8->Quit" << endl;
    // cin >> MenuChoice;
     }
    }//end of while loop
    
    
}  
//linearSearch function
int linearSearch(Account** arr, int size, int value)
{
    int index = 0;
    int position = -1;
    bool found = false;
    
    while(index < size && !found)
    {
        if(arr[index]->getAccountNumber() == value)
        {
            found = true;
            position = index;
        }
        index++;
    }
    return position;
}
