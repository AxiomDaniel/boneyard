#include <iostream>
using namespace std;

double solve(int a, int b, int c) {
    int vol;
    vol = a * a * b;
    cout << vol;
}

int main() {
    int a, b, x;
    cin >> a >> b >> x;

    cout << solve(a, b, x);
}