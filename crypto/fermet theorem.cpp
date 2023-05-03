#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()

// Function to calculate the modular exponentiation of a^b mod m
long long mod_exp(long long a, long long b, long long m) {
    long long result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % m;
        }
        a = (a * a) % m;
        b /= 2;
    }
    return result;
}

// Function to check if a number is prime using Fermat's Little Theorem
bool is_prime(long long p) {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Choose a random number between 2 and p-1
    long long a = rand() % (p - 2) + 2;

    // Check if a^(p-1) = 1 (mod p)
    return mod_exp(a, p - 1, p) == 1;
}

int main() {
    // Test if some numbers are prime using Fermat's Little Theorem
    std::cout << "7 is prime: " << is_prime(7) << std::endl;  // true
    std::cout << "15 is prime: " << is_prime(15) << std::endl;  // false
    std::cout << "23 is prime: " << is_prime(23) << std::endl;  // true
    std::cout << "1001 is prime: " << is_prime(1001) << std::endl;  // false

    return 0;
}

