#include <iostream>
#include <string>
#include <map>

std::string encrypt(std::string message, const std::map<char, char>& key) {
    std::string encrypted;
    for (char c : message) {
        // If the character is in the key, replace it with the corresponding cipher character
        std::map<char, char>::const_iterator it = key.find(std::tolower(c));
        if (it != key.end()) {
            encrypted += std::isupper(c) ? std::toupper(it->second) : it->second;
        } else {
            encrypted += c;
        }
    }
    return encrypted;
}

int main() {
    std::string message = "hello world";
    std::map<char, char> key = {
        {'a', 'd'}, {'b', 'e'}, {'c', 'f'}, {'d', 'g'}, {'e', 'h'},
        {'f', 'i'}, {'g', 'j'}, {'h', 'k'}, {'i', 'l'}, {'j', 'm'},
        {'k', 'n'}, {'l', 'o'}, {'m', 'p'}, {'n', 'q'}, {'o', 'r'},
        {'p', 's'}, {'q', 't'}, {'r', 'u'}, {'s', 'v'}, {'t', 'w'},
        {'u', 'x'}, {'v', 'y'}, {'w', 'z'}, {'x', 'a'}, {'y', 'b'}, {'z', 'c'}
    };
    std::string encrypted = encrypt(message, key);
    std::cout << "Original message: " << message << std::endl;
    std::cout << "Encrypted message: " << encrypted << std::endl;
    return 0;
}

