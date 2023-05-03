#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n = 3;
    int a[] = {2, 3, 2};
    int p[] = {3, 5, 7};
    int P = 1;

    for (int i = 0; i < n; i++) {
        P *= p[i];
    }

    int x = 0;
    for (int i = 0; i < n; i++) {
        int Pi = P / p[i];
        x += a[i] * Pi * ((int) pow(Pi, -1) % p[i]);
    }

    cout << "x = " << x % P << endl;

    return 0;
}

