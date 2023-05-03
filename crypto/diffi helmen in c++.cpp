#include <iostream>
#include <cmath>

// Function to compute the modular exponentiation a^b mod m
int mod_exp(int a, int b, int m) {
    int result = 1;
    a = a % m;
    while (b > 0) {
        if (b & 1) {
            result = (result * a) % m;
        }
        b >>= 1;
        a = (a * a) % m;
    }
    return result;
}

// Function to generate the shared secret key
int generate_shared_secret(int p, int g, int a, int b) {
    // Compute A = g^a mod p and B = g^b mod p
    int A = mod_exp(g, a, p);
    int B = mod_exp(g, b, p);

    // Compute the shared secret key K = B^a mod p = A^b mod p
    int K1 = mod_exp(B, a, p);
    int K2 = mod_exp(A, b, p);

    // Verify that both computations yield the same result
    if (K1 != K2) {
        std::cerr << "Error: shared secret key mismatch" << std::endl;
        return -1;
    }

    return K1;
}

int main() {
    // Choose a large prime number p
    int p = 23;

    // Choose a primitive root g of p
    int g = 5;

    // Choose two random secret integers a and b
    int a = 6;
    int b = 15;

    // Compute the shared secret key K
    int K = generate_shared_secret(p, g, a, b);

    if (K != -1) {
        std::cout << "Shared secret key: " << K << std::endl;
    }

    return 0;
}

