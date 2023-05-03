#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int main() {
    int p = 3, q = 7; // choose two prime numbers
    int n = p * q;
    int phi = (p-1) * (q-1);

    // choose public key e
    int e = 2;
    while (e < phi) {
        if (gcd(e, phi) == 1)
            break;
        e++;
    }

    // compute private key d
    int k = 2;
    int d = (1 + (k * phi)) / e;

    // encryption
    int plaintext = 9; // choose a message to encrypt
    int ciphertext = pow(plaintext, e);
    ciphertext %= n;

    // decryption
    int decrypted = pow(ciphertext, d);
    decrypted %= n;

    cout << "Public key (n,e): (" << n << "," << e << ")" << endl;
    cout << "Private key (n,d): (" << n << "," << d << ")" << endl;
    cout << "Plaintext: " << plaintext << endl;
    cout << "Ciphertext: " << ciphertext << endl;
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}

