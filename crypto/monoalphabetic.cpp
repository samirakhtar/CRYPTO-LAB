#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string generateKey() {
    string key = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
    return key;
}

string encrypt(string plaintext, string key) {
    string ciphertext = "";
    for(int i = 0; i < plaintext.length(); i++) {
        int p = plaintext[i] - 'A';
        int c = key[p] - 'A';
        ciphertext += c + 'A';
    }
    return ciphertext;
}

string decrypt(string ciphertext, string key) {
    string plaintext = "";
    for(int i = 0; i < ciphertext.length(); i++) {
        int c = ciphertext[i] - 'A';
        int p = key.find(c + 'A');
        plaintext += p + 'A';
    }
    return plaintext;
}

int main() {
    string plaintext = "HELLO";
    transform(plaintext.begin(), plaintext.end(), plaintext.begin(), ::toupper);

    string key = generateKey();
    string ciphertext = encrypt(plaintext, key);
    string decryptedtext = decrypt(ciphertext, key);

    cout << "Plaintext: " << plaintext << endl;
    cout << "Key: " << key << endl;
    cout << "Ciphertext: " << ciphertext << endl;
    cout << "Decryptedtext: " << decryptedtext << endl;

    return 0;
}

