// Copyright 2025 <Sparta>
#include <iostream>
#include "Vector.h"

int main() {
    try {
        Vector<int> vec;
        vec.push_back(10);
        std::cout << "vec capacity : " << vec.getCapcity()
            << " size : " << vec.getSize() << "\n";
        vec.push_back(20);
        std::cout << "vec capacity : " << vec.getCapcity()
            << " size : " << vec.getSize() << "\n";
        vec.push_back(30);
        std::cout << "vec capacity : " << vec.getCapcity()
            << " size : " << vec.getSize() << "\n";

        for (const int& num : vec) {
            std::cout << "Num: " << num << "\n";
        }

        vec.pop_back();

        for (const int& num : vec) {
            std::cout << "Num: " << num << "\n";
        }

        vec.pop_back();
        vec.pop_back();
        vec.pop_back();
    } catch (const std::exception& e) {
        std::cout << "error : " << e.what() << "\n";
    }

    try {
        Vector<int> vec2(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });

        for (const int& num : vec2) {
            std::cout << "Num: " << num << "\n";
        }
    } catch (const std::exception& e) {
        std::cout << "error : " << e.what() << "\n";
    }

    return 0;
}
