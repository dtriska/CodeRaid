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

std::string selectRandomAnimal() {
    std::vector<std::string> animal = {"Rat", "Ox", "Tiger", "Rabbit", "Dragon", "Snake",
                                         "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig"};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<std::vector<std::string>::size_type> dis(0, animal.size() - 1);
    return animal[dis(gen)];
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
    std::random_device rd;
    std::mt19937 gen(rd());

    // Shuffle the choices
    std::shuffle(choices.begin(), choices.end(), gen);

    // Create a vector to store the first 4 shuffled choices
    std::vector<std::string> selectedChoices(choices.begin(), choices.begin() + 4);

    // Display the choices
    std::cout << "Random choices:" << std::endl;
    for (const auto& choice : selectedChoices) {
        std::cout << choice << std::endl;
    }

    return selectedChoices;
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


std::vector<std::vector<std::string>> populateRooms(const std::vector<std::string>& pillarKey) {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::vector<std::vector<std::string>> roomsSymbols(12, std::vector<std::string>(4));
    std::cout << "HERE" << std::endl;

    // Create a list of all animal symbols except those in pillarKey
    std::vector<std::string> availableSymbols;
    for (const auto symbol : {"Rat", "Ox", "Tiger", "Rabbit", "Dragon", "Snake",
                          "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig"}) {
    std::cout << "Checking symbol: " << symbol << std::endl;
    if (std::find(pillarKey.begin(), pillarKey.end(), std::string(symbol)) == pillarKey.end()) {
        std::cout << "Symbol " << symbol << " is not in pillarKey. Adding to availableSymbols." << std::endl;
        availableSymbols.push_back(symbol);
    } else {
        std::cout << "Symbol " << symbol << " is in pillarKey. Skipping." << std::endl;
    }
}

    // Print the size of availableSymbols
    std::cout << "Size of availableSymbols: " << availableSymbols.size() << std::endl;

    // Shuffle the list of available symbols
    std::shuffle(availableSymbols.begin(), availableSymbols.end(), gen);

    // Populate the first 9 rooms with symbols from pillarKey and availableSymbols
    for (std::vector<std::vector<std::string>>::size_type roomNumber = 0; roomNumber < 9; ++roomNumber) {
        // First symbol from pillarKey
        roomsSymbols[roomNumber][0] = pillarKey[roomNumber % pillarKey.size()];

        // Remaining symbols from availableSymbols
        for (std::vector<std::vector<std::string>>::size_type j = 1; j < 4; ++j) {
            if (j - 1 < availableSymbols.size()) {
                roomsSymbols[roomNumber][j] = availableSymbols[j - 1];
            } else {
                // Handle case where j - 1 is out of bounds
                // For example, set the symbol to an empty string
                roomsSymbols[roomNumber][j] = ""; // Or any appropriate handling
            }
        }
    }

    // Populate the remaining 3 rooms with symbols from availableSymbols
    for (std::vector<std::vector<std::string>>::size_type roomNumber = 9; roomNumber < 12; ++roomNumber) {
        // Debug print statement to verify if the loop is being executed
        std::cout << "Entering loop for room " << roomNumber << std::endl;

        for (std::vector<std::vector<std::string>>::size_type j = 0; j < 4; ++j) {
            // Choose a random symbol from availableSymbols
            std::uniform_int_distribution<std::size_t> distribution(0, availableSymbols.size() - 1);
            roomsSymbols[roomNumber][j] = availableSymbols[distribution(gen)];
        }
    }
    return roomsSymbols;
}




void printRooms(const std::vector<std::vector<std::string>>& roomsSymbols) {
    for (size_t i = 0; i < roomsSymbols.size(); ++i) {
        std::cout << "Room " << (i + 1) << " symbols:" << std::endl;
        for (const std::string& symbol : roomsSymbols[i]) {
            std::cout << symbol << std::endl;
        }
        std::cout << std::endl;
    }
}


int main() {
    std::string color = selectRandomColor();
    std::cout << color;

    std::string welcomeMessage = "Welcome to the vault. To progress you will need to know the following: ";
    typeText(welcomeMessage);
    displayHelp();

    std::string constellationKey = sky();

    bool pillarPass = false;
    std::vector<std::string> pillarKey = pillar();

    // Call populateRooms to get the symbols for each room
    std::vector<std::vector<std::string>> roomsSymbols = populateRooms(pillarKey);
    
    // Shuffle the rooms
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(roomsSymbols.begin(), roomsSymbols.end(), gen);

    // Print the symbols for each room
    printRooms(roomsSymbols);

    std::string choice;
    std::cin >> choice;

    if (choice == "terminal") {
        if (accessTerminal(color) == true) {
            for (std::vector<std::string>::size_type i = 0; i < 4; ++i) {
                std::cout << pillarKey[i] << std::endl;
            }
            pillarPass = true;
        }
    } else if (choice == "pillar") {
        if (pillarPass == true){
            for (std::vector<std::string>::size_type i = 0; i < 4; ++i) {
                std::cout << pillarKey[i] << std::endl;
            }
        } else {
            std::cout << "Access Denied" << std::endl;
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
