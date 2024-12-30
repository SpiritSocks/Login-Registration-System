#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <openssl/sha.h>

class Account {
private:
    std::string name;
    std::string password;
    std::string emailAddress;
public:
    Account();
    Account(std::string const &name, std::string const &password, std::string const &emailAddress) {
        this->name = name;
        this->password = password;
        this->emailAddress = emailAddress;
    }
    std::string getName() const {
        return this->name;
    }
    std::string getPassword() const {
        return this->password;
    }
    std::string getEmailAddress() const {
        return this->emailAddress;
    }
};

inline std::vector<Account> container;

void AddAccount(Account newAcc);
void RefreshAccountMem();
void DeleteAccount(std::string &name, std::vector<Account> &container);

bool AccountExists(std::string name);
bool ValidEmailAddress(std::string &emailAddress);

std::string Hash(const std::string& password);

#endif
