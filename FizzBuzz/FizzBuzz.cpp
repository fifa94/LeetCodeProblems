#include <vector>
#include <iostream>
#include<string>

class Solution
{
public:
    std::vector<std::string> fizzBuzz(int n)
    {

        std::vector<std::string> results;

        for (int i = 1; i < n + 1; i++)
        {
            if ((i % 3 == 0) && (i % 5 == 0))
            {
                results.push_back("FizzBuzz");
            }
            else if (i % 3 == 0)
            {
                results.push_back("Fizz");
            }
            else if (i % 5 == 0)
            {
                results.push_back("Buzz");
            }
            else
            {
                results.push_back(std::to_string(i));
            }

            std::cout<< results[i];
        }

        return results;

    }
};

int main()
{
    Solution SolutionObj;
    SolutionObj.fizzBuzz(5);
    return 0;
}