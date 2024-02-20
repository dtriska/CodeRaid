#include <iostream>
#include <string>

int main() {
    std::string password;
    std::cout << "Enter the password: ";
    std::cin >> password;

    // Put a password
    if (password != "secret") {
        std::cout << "Incorrect password. Exiting...\n";
        return 1; // Terminate the program with an error code
    }

    // If the password is correct, continue execution
    std::cout << "Access granted! Welcome.\n";
    
    // Rest of your program goes here

    return 0; // Program executed successfully
}
