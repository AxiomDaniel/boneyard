#include <iostream>
using namespace std;

string solve(int n) {
    int x;
    for (int i = 1; i < 10; i++) {
        if (n % i == 0) {
            x = n / i;
            if (x < 10) {
                return "Yes";
            }
        }
    }
    return "No";
}

int main() {
    int n;
    cin >> n;

    cout << solve(n);

    return 0;
}