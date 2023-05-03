#include <iostream>
#include <string>

std::string encrypt(std::string message, int shift) {
    std::string encrypted;
    for (int i = 0; i < message.length(); i++) {
        char c = message[i];
        if (std::isalpha(c)) {
            // Shift the character by the specified number of positions
            char shifted = std::toupper(c) + shift;
            if (shifted > 'Z') {
                shifted -= 26;  // Wrap around to the beginning of the alphabet if needed
            }
            encrypted += std::isupper(c) ? shifted : std::tolower(shifted);
        } else {
            encrypted += c;  // Keep non-alphabetic characters unchanged
        }
    }
    return encrypted;
}

int main() {
    std::string message = "HELLO WORLD";
    int shift = 3;
    std::string encrypted = encrypt(message, shift);
    std::cout << "Original message: " << message << std::endl;
    std::cout << "Encrypted message: " << encrypted << std::endl;
    return 0;
}

