#include <iostream>

int main() {
    long n{}, m{}, a{};

    
    std::cin >> n;
    std::cin >> m;
    std::cin >> a;

    long long horizontal{ n / a }, vertical{ m / a };
    if (n % a != 0) { horizontal++; };
    if (m % a != 0) { vertical++; };

    std::cout << horizontal * vertical << "\n";
}

