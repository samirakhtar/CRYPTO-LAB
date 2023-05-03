#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string generateKey(string keyword, int n) {
    string key = "";
    int j = 0;
    for(int i = 0; i < n; i++) {
        key += keyword[j];
        j = (j + 1) % keyword.length();
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
    string plaintext = "HELLO";
    string keyword = "KEY";
    string key = generateKey(keyword, plaintext.length());
    transform(plaintext.begin(), plaintext.end(), plaintext.begin(), ::toupper);

    string ciphertext = encrypt(plaintext, key);
    string decryptedtext = decrypt(ciphertext, key);

    cout << "Plaintext: " << plaintext << endl;
    cout << "Keyword: " << keyword << endl;
    cout << "Key: " << key << endl;
    cout << "Ciphertext: " << ciphertext << endl;
    cout << "Decryptedtext: " << decryptedtext << endl;

    return 0;
}

