#include <algorithm>
#include <iostream>
using namespace std;

struct Pair {
    long a;
    long f;
    long score;
    Pair(long coeff, long food) {
        a = coeff;
        f = food;
        score = a * f;
    }
};

int main() {
    // int n;
    // long k;
    // cin >> n >> k;

    Pair pairOne(3, 6);
    cout << pairOne.a << " " << pairOne.f << " " << pairOne.score << endl;
}