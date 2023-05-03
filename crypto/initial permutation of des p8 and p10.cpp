#include <iostream>

using namespace std;

const int P10[] = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6};
const int P8[] = {6, 3, 7, 4, 8, 5, 10, 9};

int main()
{
    string key;
    cout << "Enter 10-bit key: ";
    cin >> key;

    // Permute using P10
    char temp_key[11] = {};
    for (int i = 0; i < 10; i++) {
        int index = P10[i] - 1;
        temp_key[i] = key[index];
    }

    // Print the result of P10
    cout << "Result of P10: ";
    for (int i = 0; i < 10; i++) {
        cout << temp_key[i];
    }
    cout << endl;

    // Discard the leftmost and rightmost bits
    char left_shift[11] = {};
    for (int i = 0; i < 5; i++) {
        left_shift[i] = temp_key[(i + 1) % 5];
        left_shift[i + 5] = temp_key[((i + 1) % 5) + 5];
    }

    // Print the result of left shift
    cout << "Result of left shift: ";
    for (int i = 0; i < 10; i++) {
        cout << left_shift[i];
    }
    cout << endl;

    // Permute using P8
    char sub_key[9] = {};
    for (int i = 0; i < 8; i++) {
        int index = P8[i] - 1;
        sub_key[i] = left_shift[index];
    }

    // Print the result of P8
    cout << "Result of P8: ";
    for (int i = 0; i < 8; i++) {
        cout << sub_key[i];
    }
    cout << endl;

    return 0;
}

