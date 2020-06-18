#include <iostream>


int main() {
    int x{};
    std::cin >> x;
    
    if (x != 2 && x % 2 == 0) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
    
    return 0;
}
