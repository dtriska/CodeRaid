#include <iostream>
#include <string>
#include <cctype> // for isalpha() and isupper()

using namespace std;

// Function to encrypt a message using substitution cipher
string encrypt(string message, const string& key) {
    string encrypted_message = "";
    size_t key_length = key.length();
    size_t key_index = 0; // Initialize index for cycling through the key

    for (char ch : message) {
        if (isalpha(ch)) { // Check if the character is alphabetic
            char substitute_char;
            char offset = isupper(ch) ? 'A' : 'a';
            substitute_char = (ch - offset + key[key_index % key_length] - 'A') % 26 + offset;
            encrypted_message += substitute_char;
            key_index = (key_index + 1) % key_length; // Move to the next character in the key
        } else {
            encrypted_message += ch; // Non-alphabetic characters remain unchanged
        }
    }
    return encrypted_message;
}

// Function to decrypt a message encrypted using substitution cipher
string decrypt(string message, const string& key) {
    string decrypted_message = "";
    size_t key_length = key.length();
    size_t key_index = 0; // Initialize index for cycling through the key

    for (char ch : message) {
        if (isalpha(ch)) { // Check if the character is alphabetic
            char original_char;
            char offset = isupper(ch) ? 'A' : 'a';
            original_char = (ch - offset + 26 - (key[key_index % key_length] - 'A')) % 26 + offset;
            decrypted_message += original_char;
            key_index = (key_index + 1) % key_length; // Move to the next character in the key
        } else {
            decrypted_message += ch; // Non-alphabetic characters remain unchanged
        }
    }
    return decrypted_message;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " [encrypt/decrypt]" << endl;
        return 1;
    }

    string operation = argv[1];

    if (operation != "encrypt" && operation != "decrypt") {
        cerr << "Invalid operation. Please specify 'encrypt' or 'decrypt'." << endl;
        return 1;
    }

    string key, message;

    cout << "Enter the key: ";
    cin >> key;

    cout << "Enter the message: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, message);

    if (operation == "encrypt") {
        // Encrypt the message
        string encrypted_message = encrypt(message, key);
        cout << "Encrypted message: " << encrypted_message << endl;
    } else {
        // Decrypt the message
        string decrypted_message = decrypt(message, key);
        cout << "Decrypted message: " << decrypted_message << endl;
    }

    return 0;
}
