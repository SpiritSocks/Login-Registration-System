#include "header.h"
#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>
void AddAccount(Account newAcc) {
    std::ofstream file;
    file.open("/Users/valerat/Desktop/C++/Login_&_Registration_System/database2.csv", std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Error opening database file" << std::endl;
        return;
    }
    container.push_back(newAcc);
    file << newAcc.getName() << "," << newAcc.getPassword() << "," << newAcc.getEmailAddress() << std::endl;
    file.close();
}

void RefreshAccountMem() {
    std::ifstream file;
    file.open("/Users/valerat/Desktop/C++/Login_&_Registration_System/database2.csv", std::ios::in);
    if (!file.is_open()) {
        std::cerr << "Error opening database file" << std::endl;
        return;
    }

    container.clear();

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string cell;
        std::vector<std::string> values;

        while (std::getline(iss, cell, ',')) {
            values.push_back(cell);
        }

        if (values.size() == 3) {
            container.emplace_back(values[0], values[1], values[2]);
        }
    }
    file.close();
}

void DeleteAccount(std::string &name, std::vector<Account> &container) {

    //Opening file for reading
    std::ifstream file("/Users/valerat/Desktop/C++/Login_&_Registration_System/database2.csv");
    if (!file.is_open()) {
        std::cerr << "Error opening database file" << std::endl;
        return;
    }

    //vector for containing the non-deleted accounts
    std::vector<std::string> fileLines;
    bool accountDeleted = false;

    //Here we are checking whether the account with the given name exists
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string cell;
        std::vector<std::string> values;

        while (std::getline(iss, cell, ',')) {
            values.push_back(cell);
        }

        if (values.size() == 3) {
            Account tempAcc(values[0], values[1], values[2]);
            //If the account exists, and we have entered the correct password - it's deleted
            if (tempAcc.getName() == name) {
                std::string pass;
                std::cout<<"Enter password: "<<std::endl;
                std::getline(std::cin, pass);
                if (Hash(pass) == tempAcc.getPassword()) {
                    accountDeleted = true;
                    continue;
                }else { //Else - it exits the program, and you'll have to try again later
                    std::cout<<"Wrong password!"<<std::endl;
                    exit(0);
                }
            }
        }

        fileLines.push_back(line);
    }
    file.close();


    //Erasing the deleted account from container
    for (auto it = container.begin(); it != container.end(); ++it) {
        if (it->getName() == name) {
            container.erase(it);
            break;
        }
    }

    //Rewriting the file without the deleted account
    std::ofstream outFile("/Users/valerat/Desktop/C++/Login_&_Registration_System/database2.csv", std::ios::trunc);
    if (!outFile.is_open()) {
        std::cerr << "Error opening file for writing" << std::endl;
        return;
    }

    for (const auto& fileLine : fileLines) {
        outFile << fileLine << std::endl;
    }
    outFile.close();

    if (accountDeleted) {
        std::cout << "Account deleted successfully" << std::endl;
        std::cout << std::endl;
    } else {
        std::cout << "Account not found" << std::endl;
    }
}

bool ValidEmailAddress(std::string &emailAddress) {
    if (emailAddress.find('@')==std::string::npos) {
        return false;
    }
    std::ifstream domainsfile;
    domainsfile.open("/Users/valerat/Desktop/C++/Login_&_Registration_System/domains.txt");
    std::string textLine;
    while (std::getline(domainsfile, textLine)) {
        if (emailAddress.substr(emailAddress.find('@')+1, textLine.length()) == textLine) {
            return true;
        }
    }
    domainsfile.close();
    return false;
}


std::string Hash(const std::string &password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];

    // Compute SHA-256 hash
    SHA256(reinterpret_cast<const unsigned char*>(password.c_str()), password.size(), hash);

    // Convert the hash to a hexadecimal string
    std::string hex_string;
    for (size_t i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        hex_string += "0123456789abcdef"[hash[i] >> 4];   // high nibble
        hex_string += "0123456789abcdef"[hash[i] & 0x0F]; // low nibble
    }

    return hex_string;
}