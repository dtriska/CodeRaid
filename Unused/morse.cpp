#include <iostream>
#include <map>
#include <string>
#include <cctype>
#include <thread> // For std::this_thread::sleep_for
#include <chrono> // For std::chrono::milliseconds

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

int main() {
    std::string input;
    std::cout << "Enter String: ";
    std::getline(std::cin, input);

    std::string morse = toMorse(input);
    type_text(morse);

    return 0;
}
