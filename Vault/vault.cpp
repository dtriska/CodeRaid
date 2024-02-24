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

std::vector<std::string> pillar() {
    std::vector<std::string> choices = {"Rat", "Ox", "Tiger", "Rabbit", "Dragon", "Snake",
                                         "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig"};
    // Shuffle the choices
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(choices.begin(), choices.end(), gen);

    // Display the choices
    std::cout << "Random choices:" << std::endl;
    for (std::vector<std::string>::size_type i = 0; i < 4; ++i) {
        std::cout << choices[i] << std::endl;
    }

    return choices;
}


std::string sky() {
    std::vector<std::string> star_constellations = {
        "Ursa Major", "Orion", "Cassiopeia", "Scorpius", "Taurus", "Gemini", 
        "Canis Major", "Leo", "Virgo", "Pegasus", "Draco", "Aquarius", 
        "Lyra", "Cygnus", "Sagittarius"
    };
    // Define a static variable to keep track of whether sky has been called before
    static bool calledBefore = false;

    // If sky has not been called before
    if (!calledBefore) {
        std::cout << "Random choice:" << std::endl;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::shuffle(star_constellations.begin(), star_constellations.end(), gen); // Shuffle the constellations
        // Display the chosen constellation
        std::cout << star_constellations[0] << std::endl; // Display the first (random) constellation
        calledBefore = true; // Update calledBefore to true
        return star_constellations[0];
    } else {
        std::cout << "Previous choice:" << std::endl;
        // Display the first constellation as the previous choice since the list is shuffled each time
        std::cout << star_constellations[0] << std::endl;
        return star_constellations[0];
    }
}

void rooms() {
    std::cout << "Welcome to the rooms!" << std::endl;

    // Prompt the user to select a room
    int roomNumber;
    std::cout << "Please select a room between 1 and 12: ";
    std::cin >> roomNumber;

    // Validate the room number
    if (roomNumber < 1 || roomNumber > 12) {
        std::cout << "Invalid room number!" << std::endl;
        return;
    }

    // Prompt the user to enter the passkey
    std::string passkey;
    std::cout << "Please enter the passkey to enter room " << roomNumber << ": ";
    std::cin >> passkey;

    // Check if the passkey is correct
    std::string correctPasskey = "password"; // Change this to your desired passkey
    if (passkey == correctPasskey) {
        std::cout << "Access granted to room " << roomNumber << "!" << std::endl;
        // Perform actions for accessing the room
    } else {
        std::cout << "Incorrect passkey! Access denied to room " << roomNumber << "." << std::endl;
    }
}


int main() {
    std::string color = selectRandomColor();
    std::cout << color;

    std::string welcomeMessage = "Welcome to the vault. To progress you will need to know the following: ";
    typeText(welcomeMessage);
    displayHelp();

    std::string constellationKey = sky();
    std::vector<std::string> pillarKey;

    std::string choice;
    std::cin >> choice;

    if (choice == "terminal") {
        if (accessTerminal(color) == true) {
            pillarKey = pillar(); // REMOVE AFTER TESTING IS COMPLETED
            for (std::vector<std::string>::size_type i = 0; i < 4; ++i) {
            std::cout << pillarKey[i] << std::endl;
            }
        }
    } else if (choice == "pillar") {
        for (std::vector<std::string>::size_type i = 0; i < 4; ++i) {
        std::cout << pillarKey[i] << std::endl;
        }
    } else if (choice == "sky") {
        std::cout << "Selected constellation: " << constellationKey << std::endl;
    } else if (choice == "rooms") {
        rooms(); 
    } else if (choice == "exit") {
        // Do nothing, program will exit
    } else {
        std::cout << "Invalid choice!" << std::endl;
    }

    return 0;
}
