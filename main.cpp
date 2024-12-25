#include "header.h"

int main() {
    RefreshAccountMem();
    std::string input;

    do {
        if (container.empty()) {
            std::cout << "No accounts exist, please create one." << std::endl;
            std::string name, password, email;
            std::cout << "Please enter account name:" << std::endl;
            std::getline(std::cin, name);
            std::cout << "Please enter password:" << std::endl;
            std::getline(std::cin, password);
            std::cout << "Please enter email:" << std::endl;
            std::getline(std::cin, email);
            AddAccount(Account(name, Hash(password), email));
            std::cout << "Account added." << std::endl;
            continue;
        }

        std::cout << "Enter account username (or type 'exit' to quit):" << std::endl;
        std::getline(std::cin, input);

        if (input == "exit") {
            std::cout << "Exiting program." << std::endl;
            break;
        }

        bool found = false;
        for (const auto& c : container) {
            if (c.getName() == input) {
                found = true;
                break;
            }
        }

        if (!found) {
            std::cout << "Account doesn't exist. Create an account with the name '" << input << "'? (Y/N)" << std::endl;
            std::string choice;
            std::getline(std::cin, choice);
            std::ranges::transform(choice, choice.begin(), ::toupper);

            if (choice == "Y") {
                std::string password, email;
                std::cout << "Enter password:" << std::endl;
                std::getline(std::cin, password);
                std::cout << "Enter email:" << std::endl;
                std::getline(std::cin, email);
                AddAccount(Account(input, Hash(password), email));
                std::cout << "Account successfully created." << std::endl;
            } else {
                std::cout << "Account creation cancelled." << std::endl;
            }
        }else {
            std::cout << "Account exists, please enter your password" << std::endl;
            bool passFound = false;
            int counter = 0;
            std::string password2;
            while (counter < 3) {
                std::getline(std::cin, password2);
                std::string hashedPass = Hash(password2);
                passFound = false;

                for (const auto &c : container) {
                    if (c.getPassword() == hashedPass) {
                        passFound = true;
                        std::cout << "All good" << std::endl;
                    }
                }

                if (passFound) {
                    break;
                }else {
                    counter++;
                    if (counter < 3) {
                        std::cout << "Try again" << std::endl;
                    } else {
                        std::cout << "Try again later" << std::endl;
                    }
                }
            }
        }

    } while (true);
    return 0;
}
