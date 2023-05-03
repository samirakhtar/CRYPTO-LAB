#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

string columnar_transposition_encrypt(const string& plaintext, const string& key) {
    int key_len = key.length();
    int text_len = plaintext.length();

    // Calculate the number of rows required to fit the plaintext
    int rows = ceil((double) text_len / key_len);

    // Create a matrix to store the plaintext
    char matrix[rows][key_len];

    // Fill the matrix with the plaintext
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < key_len; j++) {
            if (index < text_len) {
                matrix[i][j] = plaintext[index++];
            } else {
                matrix[i][j] = ' ';
            }
        }
    }

    // Sort the key and get the corresponding column indices
    string sorted_key = key;
    sort(sorted_key.begin(), sorted_key.end());
    int indices[key_len];
    for (int i = 0; i < key_len; i++) {
        indices[i] = key.find(sorted_key[i]);
    }

    // Concatenate the columns to get the ciphertext
    string ciphertext;
    for (int i = 0; i < key_len; i++) {
        for (int j = 0; j < rows; j++) {
            ciphertext += matrix[j][indices[i]];
        }
    }

    return ciphertext;
}

string columnar_transposition_decrypt(const string& ciphertext, const string& key) {
    int key_len = key.length();
    int text_len = ciphertext.length();

    // Calculate the number of rows required to fit the ciphertext
    int rows = ceil((double) text_len / key_len);

    // Create a matrix to store the ciphertext
    char matrix[rows][key_len];

    // Fill the matrix with the ciphertext
    int index = 0;
    for (int i = 0; i < key_len; i++) {
        for (int j = 0; j < rows; j++) {
            matrix[j][i] = ciphertext[index++];
        }
    }

    // Get the corresponding column indices of the key
    int indices[key_len];
    for (int i = 0; i < key_len; i++) {
        indices[key.find(i + '1')] = i;
    }

    // Reconstruct the plaintext from the matrix
    string plaintext;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < key_len; j++) {
            if (matrix[i][indices[j]] != ' ') {
                plaintext += matrix[i][indices[j]];
            }
        }
    }

    return plaintext;
}

int main() {
    string plaintext = "THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG";
    string key = "342156";

    string ciphertext = columnar_transposition_encrypt(plaintext, key);
    cout << "Ciphertext: " << ciphertext << endl;

    string decrypted_plaintext = columnar_transposition_decrypt(ciphertext, key);
    cout << "Decrypted plaintext: " << decrypted_plaintext << endl;

    return 0;
}

