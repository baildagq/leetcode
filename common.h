#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

template<typename T>
void printVector(std::vector<T>& vec) {
    for (auto& item : vec) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}