#include <iostream>

using namespace std;

long long exponent(long long a, long long b) {
    if (b == 0) {
        return 1;
    }
    long long result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result = result * a;
        }
        a = a * a;
        b /= 2;
    }
    return result;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        long long a, b;
        cin >> a >> b;

        long long result = exponent(a, b);

        cout << result << endl;
    }

    return 0;
}
