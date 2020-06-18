#include <cmath>
#include <iostream>
using namespace std;

long long solve(long long n) {
    long long x, k;
    long long min{n};
    x = sqrt(n);
    for (long long i = 1; i <= x; i++) {
        if (n % i == 0) {
            k = n / i;
            min = ((k + i - 2 < min) ? k + i - 2 : min);
        }
    }
    return min;
}

int main() {
    long long n;
    cin >> n;

    cout << solve(n);
    return 0;
}