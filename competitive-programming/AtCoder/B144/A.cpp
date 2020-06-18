#include <iostream>
using namespace std;

int solve(int a, int b) {
    if (a > 9 || b > 9) {
        return -1;
    } else {
        return a * b;
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << solve(a, b);

    return 0;
}