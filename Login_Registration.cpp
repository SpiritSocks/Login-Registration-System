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
            container.emplace_back(Account(values[0], values[1], values[2]));
        }
    }
    file.close();
}
