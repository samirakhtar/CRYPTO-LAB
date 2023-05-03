#include <iostream>
#include <string>

using namespace std;

unsigned int xor_hash(const string& str) {
    unsigned int hash = 0;

    for (unsigned int i = 0; i < str.length(); i++) {
        hash ^= str[i]; // XOR each byte of the string
    }

    return hash;
}

int main() {
    string input = "Hello, world!";
    unsigned int hash = xor_hash(input);

    cout << "Input: " << input << endl;
    cout << "Hash: " << hash << endl;

    return 0;
}

