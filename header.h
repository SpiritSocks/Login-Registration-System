#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

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
    /*
    void display() const {
        std::cout << "Object(" << name << ", " << password << ", " << emailAddress << ")" << std::endl;
    }
    */
    std::string getName() const{
        return this->name;
    }
    std::string getPassword() const{
        return this->password;
    }
    std::string getEmailAddress() const{
        return this->emailAddress;
    }
};

void AddAccount(Account newAcc);
bool AccountExists(std::string name);
inline std::vector<Account> container;
void RefreshAccountMem();

inline std::string Hash(std::string str) {
    const int p =100;
    const long m=1e9+10;
    long long hash_val =0;
    long long power =1;
    for (char c : str) {
        if (isdigit(c)) {
            hash_val = (hash_val +(c - '0')*power)%m;
        }else if (isalpha(c)){
            hash_val = (hash_val + (c - 'a' + 1) * power) % m;
        }else if (ispunct(c)){
            hash_val = (hash_val + (c - ' ' + 1) * power) % m;
        }
        power = (power * p) % m;
    }
    std::string sda = std::to_string(hash_val);
    return sda;
}
#endif
