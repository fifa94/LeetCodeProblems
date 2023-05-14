#include <vector>
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#include <gmp.h>

class Solution
{
public:
    std::vector<int> plusOne(std::vector<int> &digits)
    {
        int size = digits.size();
        std::string digits_string;
        unsigned long long int number = 0;
        std::vector<int> return_vector;

        for (int i = 0; i < size; i++)
        {
            number += digits[(digits.size() - 1) - i] * ((unsigned long long int)pow(10, i));
        }

        number += 1;

        size = std::to_string(number).length();

        for (int i = 1; i < size + 1; i++)
        {
            unsigned long long int last_digit = 0;
            last_digit = number % (unsigned long long int)pow(10, i);

            number -= last_digit;

            last_digit = last_digit / pow(10, (i-1));

            return_vector.push_back(last_digit);
        }

        std::reverse(return_vector.begin(), return_vector.end());

        for (int i = 0; i < return_vector.size(); i++)
        {
            std::cout<<return_vector[i];
        }
        
        return return_vector;
    }
};

int main()
{

    std::vector<int> input_vector = {7,2,8,5,0,9,1,2,9,5,3,6,6,7,3,2,8,4,3,7,9,5,7,7,4,7,4,9,4,7,0,1,1,1,7,4,0,0,6};

    Solution SolutionObj;
    SolutionObj.plusOne(input_vector);

    return 0;
}