#include <iostream>

namespace oop3 {
    template <typename T>
    T getNum() {
        T num = 0;
        while (!(std::cin >> num)) {
            std::cout << "Try again: ";
            if (std::cin.eof()) {
                break;
            }
            std::cin.clear();
            std::cin.ignore();
        }
        return num;
    }
}