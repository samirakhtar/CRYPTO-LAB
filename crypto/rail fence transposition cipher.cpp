#include <iostream>
#include <string>

using namespace std;

string rail_fence_encrypt(const string& plaintext, int key) {
    string ciphertext;
    for (int i = 0; i < key; i++) {
        for (int j = i; j < plaintext.length(); j += 2 * key - 2) {
            ciphertext += plaintext[j];
            if (i != 0 && i != key - 1 && j + 2 * (key - i - 1) < plaintext.length()) {
                ciphertext += plaintext[j + 2 * (key - i - 1)];
            }
        }
    }
    return ciphertext;
}

string rail_fence_decrypt(const string& ciphertext, int key) {
    string plaintext(ciphertext.length(), ' ');
    int pos = 0;
    for (int i = 0; i < key; i++) {
        for (int j = i; j < ciphertext.length(); j += 2 * key - 2) {
            plaintext[j] = ciphertext[pos++];
            if (i != 0 && i != key - 1 && j + 2 * (key - i - 1) < ciphertext.length()) {
                plaintext[j + 2 * (key - i - 1)] = ciphertext[pos++];
            }
        }
    }
    return plaintext;
}

int main() {
    string plaintext = "THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG";
    int key = 3;

    string ciphertext = rail_fence_encrypt(plaintext, key);
    cout << "Ciphertext: " << ciphertext << endl;

    string decrypted_plaintext = rail_fence_decrypt(ciphertext, key);
    cout << "Decrypted plaintext: " << decrypted_plaintext << endl;

    return 0;
}

