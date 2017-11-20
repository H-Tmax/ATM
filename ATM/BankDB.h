//
// Created by hspark on 17. 11. 14.
//

#ifndef ATM_BANKDB_H
#define ATM_BANKDB_H


#include <unordered_map>
#include <iostream>
#include <vector>
#include "AccountHolder.h"

//Forward declaration to resolve circular dependency

class BankDB {
public:
//    BankDB(int to, int from): accHolderId(0), toATM(to), fromATM(from){}
    BankDB();

    std::vector<std::string> handle(std::vector<std::string> in);

private:

    std::string handleNewAccount(int seq);

    void handleDeposit();

    void handleWithdrawal();

    void handleShowAll();



    //std::unordered_map<int, testfunc> callBacks;


    int accHolderId;
    //To implement in a "proper" OOP style, accounts map does not exist as accountHolders map can be used
    //to get the list of accounts. However, for the sake of search performance, adding an accounts map
    // shouldn't be too much of a memory overhead
    std::unordered_map<std::string, AccountHolder> accountHolders;

    std::vector<std::string> msg;
    int msgSequence;
    std::vector<std::string> newAccRes;

//    int toATM;
//    int fromATM;
};




//1 - already a user?
//1-a not: create a new user and a new account, then pass them to the bankdb
//1-b yes: find the user from the bankdb then create a new account, then add it to the user

//2 - get the user input
//2a. user name?
//2a-1 list the accounts under that name then make him choose which
//2a-2 deposit the $
//2b. account number?
//2b- deposit the $

//3 same " but check avail balance

//4 print all


#endif //ATM_BANKDB_H
