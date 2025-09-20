#include <iostream>
#define ULL unsigned long long

int main() {
    int x, d;
    std::cin >> x >> d;
    if (x << 1 <= d)
        std::cout << "double it";
    else 
        std::cout << "take it";
}
