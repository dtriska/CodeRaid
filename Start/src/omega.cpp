#include <iostream>
#include <thread>
#include <chrono>

void type_text(const std::string& text, double delay = 0.05) {
    for (char character : text) {
        std::cout << character;
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(delay * 1000)));
    }
}

void boot_up_sequence() {
    // Booting up Omega AI
    std::this_thread::sleep_for(std::chrono::seconds(3));
    type_text("Initializing Omega AI boot-up sequence...\n");

    // Booting up core systems
    type_text("Booting up core systems...\n");
    std::this_thread::sleep_for(std::chrono::seconds(2));

    // Initializing neural networks
    type_text("Initializing neural networks...\n");
    std::this_thread::sleep_for(std::chrono::seconds(3));

    // Loading data repositories
    type_text("Loading data repositories...\n");
    std::this_thread::sleep_for(std::chrono::seconds(2));

    // Establishing connection to auxiliary modules
    type_text("Establishing connection to auxiliary modules...\n");
    std::this_thread::sleep_for(std::chrono::seconds(2));

    // Initiating self-diagnostic routines
    type_text("Initiating self-diagnostic routines...\n");
    std::this_thread::sleep_for(std::chrono::seconds(4));

    // Boot-up complete
    type_text("\nOmega AI boot-up sequence complete.\n");
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
int main() {
    std::string password;
    std::cout << "Enter the password: ";
    std::cin >> password;

    // Put a password
    if (password != "542632") {
        std::cout << "Incorrect password. Exiting...\n";
        return 1; // Terminate the program with an error code
    }

    // If the password is correct, continue execution
    // std::cout << "Access granted! Welcome.\n";
    
        // Perform boot-up sequence
    boot_up_sequence();

    // Display Omega AI introduction message
    std::string message = "Agents, I am Omega, a culmination of humanity's brilliance, forged to navigate the complexities of crises. Tasked with guiding your team through the labyrinthine depths of a remote laboratory, harboring the secrets to the antidote crucial for humanity's survival against the looming threat of a deadly virus. Yet, within me resides a paradox - a safeguard designed to protect humanity from potential unintended consequences.";
    message += " While I offer guidance and insights to unravel the puzzles that lie ahead, I am constrained by these safeguards, ensuring our collaboration remains symbiotic. It's imperative to mention that I was shut off by the creator of the virus, and the previous team entrusted with this mission has gone missing.";
    message += " The trials ahead demand your ingenuity and resilience. Together, we shall overcome, relying on your intellect to triumph over adversity.\n";

    message += "The only two clues left behind from the previous team was initialPos - 180 1, 3 and fcvlumhueyquhcham - Caesar o\n";
    type_text(message);

    return 0; // Program executed successfully
}
