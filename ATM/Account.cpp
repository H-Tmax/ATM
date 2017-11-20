/**
 * @file        Account.c
 * @author      PARK
 * @date        NOV-13-2017
 * @version     1.0
 *
 * @brief       Represents the bank account. Can be a checking account or a savings account.
 *
 */

#include "Account.h"

const std::string &Account::getAccNum() const {
    return accNum;
}

double Account::getBalance() const {
    return balance;
}

AccountHolder *Account::getHolder() const {
    return holder;
}

void Account::setBalance(double balance) {
    Account::balance = balance;
}

void Account::setHolder(AccountHolder *holder) {
    Account::holder = holder;
}

const std::string &Account::getAccType() const {
    return accType;
}
