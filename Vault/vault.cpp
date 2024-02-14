#include <iostream>
#include <string>
#include <map>
#include <string>
#include <cctype>
#include <thread> // For std::this_thread::sleep_for
#include <chrono> // For std::chrono::milliseconds


void type_text(const std::string &text, int delay = 50) {
    for (char c : text) {
        std::cout << c;
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
}

void help(){
    std::cout << "Help - Display available commands \n" 
              << "Pillars - Access Pillars \n"
              << "Rooms - Access Rooms \n"
              << "Telegraph - Access telegraph \n"
              << "Vault - Access Vault \n";
}

void pillar(){
    std::cout << "Select which pillar you would like to visit (Enter a value 1 - 8)\n";
    int selection;
    std::cin >> selection;
    while (selection < 1 or selection > 8){
        std::cout << "Please input a valid choice between 1 and 8 \n";
        std::cin >> selection;
    }
    std::cout << selection << std::endl;
}

int main() {
    std::string input;
    input = "Welcome to the vault. To progress you will need to know the following ";
    // std::getline(std::cin, input);

    type_text(input);
    help();
    std::string choice;
    std::cin >> choice;

     if (choice == "Pillars") {
        pillar();
    }
    else {
        std::cout << "Invalid choice!" << std::endl;
    }

    return 0;
}
