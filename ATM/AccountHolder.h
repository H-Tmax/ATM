#ifndef ATM_ACCOUNTHOLDER_H
#define ATM_ACCOUNTHOLDER_H

/**
 * @file        AccountHolder.h
 * @author      PARK
 * @date        NOV-13-2017
 * @version     1.0
 *
 * @brief       Represents the account holder. Can have multiple bank accounts.
 *
 */

#include <string>

class AccountHolder {

public:

    void setSSN(const std::string &SSN);

    void setName(const std::string &name);

    void setMobileNum(const std::string &mobileNum);

    void setAddr(const std::string &addr);

    void setEmail(const std::string &email);

    void setAge(int age);

    const std::string &getSSN() const;

    const std::string &getName() const;

    const std::string &getMobileNum() const;

    const std::string &getAddr() const;

    const std::string &getEmail() const;

    int getAge() const;

    int getId() const;

private:
    static int id;
    std::string SSN;
    std::string name;
    std::string mobileNum;
    std::string addr;
    std::string email;
    int age;
};


#endif //ATM_ACCOUNTHOLDER_H
