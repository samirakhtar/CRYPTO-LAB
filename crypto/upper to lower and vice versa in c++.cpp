#include <iostream>
#include <cctype>

int main() {
    char c;
    std::cout << "Enter a character: ";
    std::cin >> c;
    int choice;
    std::cout << "Choose an option: \n1. Convert to uppercase\n2. Convert to lowercase\n";
    std::cin >> choice;
    if (choice == 1) {
        c = toupper(c);
        std::cout << "Uppercase character: " << c << std::endl;
    } else if (choice == 2) {
        c = tolower(c);
        std::cout << "Lowercase character: " << c << std::endl;
    } else {
        std::cout << "Invalid choice!\n";
    }
    return 0;
}

