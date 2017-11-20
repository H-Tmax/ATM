
/**
 * @file        BankDB.c
 * @author      PARK
 * @date        NOV-16-2017
 * @version     1.0
 *
 * @brief       Represents the BankDB. The Controller of this project
 *
 */

#include "BankDB.h"

BankDB::BankDB() {
    this->newAccRes.push_back("");
    this->newAccRes.push_back("Please enter your name");
    this->newAccRes.push_back("Please enter your SSN");


}

std::vector<std::string> BankDB::handle(std::vector<std::string> in) {
    int handleIDX = atoi(in[0].c_str());
    //TODO: change this to callback map
    if (handleIDX == 1) {
        this->handleNewAccount(++this->msgSequence);
    }


    return this->msg;
}

std::string BankDB::handleNewAccount(int seq) {

    return newAccRes[seq];
    //give out -> welcome msg & i need your name and ssn
    //need ui -> account holder name and ssn
    //give out -> already a holder vs. new holder
    //give out -> what kind of account do you want to open today
    //need ui -> checking/savings
}