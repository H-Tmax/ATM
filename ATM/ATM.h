#ifndef ATM_ATM_H
#define ATM_ATM_H

/**
 * @file        ATM.h
 * @author      PARK
 * @date        NOV-13-2017
 * @version     1.0
 *
 * @brief       Represents the ATM. Can have multiple BankDB objects.
 *
 * TODO:        Instead of creating & having BankDB objects, connect to already established BankDB Servers.
 */

#include <vector>
#include <string>
#include <iostream>
#include <limits>
#include <unordered_map>
#include "BankDB.h"
//#include "Pipe.h"

/**
 * ATM > BankDB > AccountHolder > Account
 */


class ATM {
public:
    ATM();

    void initiate();

    std::string getUserInput();

    void printOutput(std::string);

private:
    std::vector<BankDB *> banks;

    int prompt(int rc);

    std::vector <std::string> msg;

//    void setFD(int to, int from);
//    int toBankDB;
//    int fromBankDB;

};


#endif //ATM_ATM_H
