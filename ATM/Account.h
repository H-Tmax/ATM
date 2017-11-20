#ifndef ATM_ACCOUNT_H
#define ATM_ACCOUNT_H

/**
 * @file        Account.h
 * @author      PARK
 * @date        NOV-13-2017
 * @version     1.0
 *
 * @brief       Represents the bank account. Can be a checking account or a savings account.
 *
 */

#include "AccountHolder.h"
#include <string>


class Account {
public:
    virtual void setBalance(double balance);

    virtual void setHolder(AccountHolder *holder);

    virtual const std::string &getAccNum() const;

    virtual const std::string &getAccType() const;

    virtual double getBalance() const;

    virtual AccountHolder *getHolder() const;

protected:
    std::string accNum;
    std::string accType;
    double balance;
    AccountHolder *holder;

    Account(std::string _accNum, AccountHolder *_holder, std::string _accType) : accNum(_accNum), accType(_accType),
                                                                                 balance(0), holder(_holder) {}
};

class CheckingAccount : public Account {
public:
    CheckingAccount(std::string _accNum, AccountHolder *_holder) : Account(_accNum, _holder, "CHK") {}
};

class SavingsAccount : public Account {
public:
    SavingsAccount(std::string _accNum, AccountHolder *_holder) : Account(_accNum, _holder, "SAV") {}
};


#endif //ATM_ACCOUNT_H
