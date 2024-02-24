#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <thread> // For std::this_thread::sleep_for
#include <vector>
#include <random>
#include <algorithm>

std::string selectRandomColor() {
    std::vector<std::string> colors = {"red", "orange", "yellow", "green", "blue", "purple"};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<std::vector<std::string>::size_type> dis(0, colors.size() - 1);
    return colors[dis(gen)];
}

bool accessTerminal(const std::string& color) {
    std::map<std::string, std::string> colorPasswords = {
        {"red", "red"}, {"orange", "orange"}, {"yellow", "yellow"},
        {"green", "green"}, {"blue", "blue"}, {"purple", "purple"}
    };

    std::string password = colorPasswords[color];
    std::string input;
    std::cout << "Input Inspector Key: ";
    std::cin >> input;

    if (input == password) {
        std::cout << "Success" << std::endl;
        return true;
    } else {
        std::cout << "Failure" << std::endl;
        return false;
    }
}

void typeText(const std::string& text, int delay = 50) {
    for (char c : text) {
        std::cout << c;
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
}

void displayHelp() {
    std::cout << "Available commands:\n"
              << "tablet - Access Tablet\n"
              << "pillar - Access Pillar\n"
              << "rooms - Access Rooms\n"
              << "terminal - Access Terminal\n"
              << "vault - Access Vault\n";
}

void pillar(bool terminalKey) {
    if (terminalKey == true){
    // Define the list of choices
    std::vector<std::string> choices = {"Rat", "Ox", "Tiger", "Rabbit", "Dragon", "Snake",
                                         "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig"};
    // Define a static variable to keep track of whether pillar has been called before
    static bool calledBefore = false;

    // If pillar has not been called before
    if (!calledBefore) {
        std::cout << "Random choices:" << std::endl;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::shuffle(choices.begin(), choices.end(), gen); // Shuffle the choices
        // Display the first 4 choices
        for (std::vector<std::string>::size_type i = 0; i < 4; ++i) {
            std::cout << choices[i] << std::endl;
        }
        calledBefore = true; // Update calledBefore to true
    } else {
        std::cout << "Previous choices:" << std::endl;
        // Display the previous 4 choices
        for (std::vector<std::string>::size_type i = 0; i < 4; ++i) {
            std::cout << choices[i] << std::endl;
        }
    }
    } else {
        std::cout << "Term Key == False" << std::endl;
    }
}

int main() {
    std::string color = selectRandomColor();
    std::cout << color;

    std::string welcomeMessage = "Welcome to the vault. To progress you will need to know the following: ";
    typeText(welcomeMessage);
    displayHelp();

    std::string choice;
    std::cin >> choice;

    bool termKey = false;

    if (choice == "terminal") {
        if (accessTerminal(color) == true) {
            termKey = true;
            pillar(termKey);
        }
    } else if (choice == "pillar") {
        pillar(termKey);
    } else if (choice == "exit") {
        // Do nothing, program will exit
    } else {
        std::cout << "Invalid choice!" << std::endl;
    }

    return 0;
}
