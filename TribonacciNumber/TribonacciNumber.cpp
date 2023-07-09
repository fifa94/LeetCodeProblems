#include <iostream>
#include <math.h>
#include <bits/stdc++.h>

class Solution {
public:
    int tribonacci(int n) {

    return std::round((3 * std::cbrt(586 + (102 * std::sqrt(33)))) * ((std::pow(((1. / 3.) * (std::cbrt(19 + (3 * std::sqrt(33))) + std::cbrt(19 - (3 * std::sqrt(33))) + 1)), n)) / ((std::pow(std::cbrt(586 + (102 * std::sqrt(33))), 2)) - (2 * std::cbrt(586 + (102 * std::sqrt(33)))) + 4)));      
    }
};

int main()
{
    Solution SolutionObj;
    std::cout << SolutionObj.tribonacci(5);
    return 0;
}
