#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string generateKey(int n) {
    string key = "";
    for(int i = 0; i < n; i++) {
        key += rand() % 26 + 'A';
    }
    return key;
}

string encrypt(string plaintext, string key) {
    string ciphertext = "";
    for(int i = 0; i < plaintext.length(); i++) {
        int p = plaintext[i] - 'A';
        int k = key[i] - 'A';
        int c = (p + k) % 26;
        ciphertext += c + 'A';
    }
    return ciphertext;
}

string decrypt(string ciphertext, string key) {
    string plaintext = "";
    for(int i = 0; i < ciphertext.length(); i++) {
        int c = ciphertext[i] - 'A';
        int k = key[i] - 'A';
        int p = (c - k + 26) % 26;
        plaintext += p + 'A';
    }
    return plaintext;
}

int main() {
    srand(time(NULL));
    string plaintext = "HELLO";
    string key = generateKey(plaintext.length());
    string ciphertext = encrypt(plaintext, key);
    string decryptedtext = decrypt(ciphertext, key);

    cout << "Plaintext: " << plaintext << endl;
    cout << "Key: " << key << endl;
    cout << "Ciphertext: " << ciphertext << endl;
    cout << "Decryptedtext: " << decryptedtext << endl;

    return 0;
}

