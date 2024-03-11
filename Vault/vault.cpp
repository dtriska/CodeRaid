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

void rooms(const std::vector<std::vector<std::string>>& roomsSymbols, const std::string constellationKey) {
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
    std::string correctPasskey = constellationKey; // Change this to your desired passkey
    if (passkey == correctPasskey) {
        std::cout << "Access granted to room " << roomNumber << "!" << std::endl;
        // Display the contents of the specified room
        std::cout << "Contents of room " << roomNumber << ":" << std::endl;
        for (const std::string& symbol : roomsSymbols[roomNumber - 1]) {
            std::cout << symbol << std::endl;
        }
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

void beacons(const std::string& message) {
    // Implement the beacons functionality here
    std::cout << "Beacons: " << message << std::endl;
}

std::map<char, std::string> morseCode = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."},
    {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
    {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."},
    {'S', "..."}, {'T', "-"}, {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
    {'Y', "-.--"}, {'Z', "--.."}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"},
    {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."},
    {'9', "----."}, {'0', "-----"}, {' ', " "}
};

std::string toMorse(const std::string &text){
    std::string morse;
    for (char c: text){
        c = toupper(c);
        if (morseCode.find(c) != morseCode.end()){
            morse += morseCode[c] + " ";
        } else {
            morse += "? "; // Question mark for unknown characters
        }
    }
    return morse;
}

void type_text(const std::string &text, int delay = 200) {
    for (char c : text) {
        std::cout << c;
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
}

// Function to generate a random choice between "CW" and "CCW"
std::string getRandomDirection() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 1);
    return (dis(gen) == 0) ? "CW" : "CCW";
}

// Function to generate a random number between 1 and 11
int getRandomNumber() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 11);
    return dis(gen);
}

// Function to generate the Morse string
std::string genMorse() {
    std::string direction = getRandomDirection();
    int number = getRandomNumber();
    return direction + " " + std::to_string(number);
}

void vault(const std::string& message) {
    std::string input;
    std::cout << "Welcome to the vault. What would you like to do?\n"
                 "telegraph\n"
                 "beacons\n"
                 "Enter your choice: ";
    std::cin >> input;

    if (input == "telegraph") {
        std::string morse = toMorse(message);
        type_text(morse);
    } else if (input == "beacons") {
        beacons(message);
    } else {
        std::cout << "Invalid choice!" << std::endl;
    }
}

std::vector<std::vector<std::string>> vault_beacons(std::vector<std::vector<std::string>> roomsSymbols){
    std::vector<std::vector<std::string>> beacons;
    for (std::vector<std::vector<std::string>>::size_type roomNumber = 9; roomNumber < 12; ++roomNumber) {
        std::vector<std::string> beacon;
        for (std::vector<std::vector<std::string>>::size_type j = 0; j < 4; ++j) {
            beacon.push_back(roomsSymbols[roomNumber][j]);
        }
        beacons.push_back(beacon);
    }
    return beacons;
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

    // Beacons will store the 3 rooms which are about to be randomized. Needed for vault
    std::vector<std::vector<std::string>> beacon_nums = vault_beacons(roomsSymbols); 
    
    // Shuffle the rooms
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(roomsSymbols.begin(), roomsSymbols.end(), gen);

    // Print the symbols for each room
    printRooms(roomsSymbols);

    // generate morse code
    std::string morse = genMorse();

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
        rooms(roomsSymbols, constellationKey); // Pass roomsSymbols to the rooms function
    } else if (choice == "vault") {
    // Call the vault function with the Morse message
        vault(morse); // Replace "Your message" with the actual message
    } else if (choice == "exit") {
        // Do nothing, program will exit
    } else {
        std::cout << "Invalid choice!" << std::endl;
    }

    return 0;
}
