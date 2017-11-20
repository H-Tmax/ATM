
/**
 * @file        ATM.c
 * @author      PARK
 * @date        NOV-13-2017
 * @version     1.0
 *
 * @brief       Represents the ATM. Can have multiple BankDB objects.
 *
 * TODO:        Instead of creating & having BankDB objects, connect to already established BankDB Servers.
 */

#include "ATM.h"

/**
 * Default constructor
 */
ATM::ATM() {
    this->initiate();
}

/**
 * For now, proceed with creating one BankDB instance presuming there is only one BankDB
 * TODO:    IMPLEMENT SOME EXCEPTION HANDLING WITH TRY/CATCH
 * TODO:    vector should contain the list of available BankDB servers
 *          then this function loops through the list and connects to those BankDB servers.
 * TODO:    PASSWORD PROTECTION OF EACH STEP
 * TODO:    DATA STORED OUTSIDE OF THE RUNTIME - ENCRYPTION OF STORED DATA
 */
void ATM::initiate() {
    //TODO: There should be a list of available BankDB instances that ATM can connect to
//    Pipe atmPipe;
//    Pipe bankDBPipe;
//    this->setFD(bankDBPipe.getReadFD(), atmPipe.getWriteFD());
//    banks.push_back(new BankDB(atmPipe.getReadFD(), bankDBPipe.getWriteFD()));

    banks.push_back(new BankDB());

    int rc = 0;

    while (true) {
        rc = prompt(rc);
        if (rc == 5) {
            break;
        }
        //atm to bank msg => [rc, uin]
        //bank to atm msg => [need uin flag, print msg]
        //1this->msg[0] = std::to_string(rc);
        std::string a;
        a = std::to_string(rc);
        std::cout << a << "test1" << std::endl;
        this->msg.push_back(a);
        while ((banks[0]->handle(this->msg))[0] != "FIN") {
            this->msg = banks[0]->handle(this->msg);
            this->printOutput(msg[1]);
            this->msg.clear();

            this->msg[1] = this->getUserInput();
        }
        this->printOutput(banks[0]->handle(this->msg)[1]);

        //while received message's  first elem is not "fin"
        // ->print the second elem
        // ->clear the msg, set first elem as rc
        // ->set the second elem as input
        // ->send the msg to bankDB to handle


        //ATM(view) should do nothing with the processing of the logic
        //except for further processing of user I/O
        //something = banks[0]->handle(rc);
        //std::cout << something.pop() << std::endl;
        //if (!something.empty()){
        //
        //}

        //ATM(view) should do nothing with the processing of the logic except for further processing of user I/O

    }
}

/**
 * Print out the main UI for the program that interacts with the user
 * @return user input
 */
int ATM::prompt(int rc) {
    std::cout << "\n\n\t\t\t\tWELCOME TO SUPER ATM" << std::endl;
    std::cout << "\nPLEASE TELL ME WHAT YOU WANT TO DO TODAY BY ENTERING A NUMBER" << std::endl;
    std::cout << "\n1. OPEN A NEW ACCOUNT" << std::endl;
    std::cout << "\n2. DEPOSIT" << std::endl;
    std::cout << "\n3. WITHDRAWAL" << std::endl;
    std::cout << "\n4. SHOW ENTIRE DB BECAUSE WHY THE FUCKING NOT" << std::endl;
    std::cout << "\n5. END THIS MISERY" << std::endl;

    if (!(std::cin >> rc) || rc < 1 || rc > 5) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\n\n\n\n\n[ERROR] WRONG USER INPUT" << std::endl;
        std::cout << "......YOU HAD A VERY SIMPLE TASK. TRY AGAIN, AND TRY NOT TO FAIL ME AGAIN" << std::endl;
        rc = prompt(rc);
    }
    return rc;
}


std::string ATM::getUserInput() {
    std::string in;
    std::cin >> in;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return in;
}

void ATM::printOutput(std::string in) {
    std::cout << in << std::endl;
}

//void ATM::setFD(int to, int from) {
//    this->toBankDB = to;
//    this->fromBankDB = from;
//}


