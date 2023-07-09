#include <vector>
#include <iostream>

class Solution
{
public:
    std::vector<int> plusOne(std::vector<int> &digits)
    {
        digits[digits.size() - 1] += 1;

        if (digits[digits.size() - 1] == 10)
        {
            int index = digits.size() - 1;

            do
            {
                if (digits[index] == 10)
                {
                    digits[index] = 0;

                    if ((index) == 0)
                    {
                        digits.insert(digits.begin(), 1);
                    }
                    else
                    {
                        digits[index - 1] += 1;
                    }
                }
                
                index--;

            } while (index + 1 > 0);
            
        }

        return digits;
    }
};

int main()
{

    // std::vector<int> input_vector = {7,2,8,5,0,9,1,2,9,5,3,6,6,7,3,2,8,4,3,7,9,5,7,7,4,7,4,9,4,7,0,1,1,1,7,4,0,0,9};
    std::vector<int> input_vector = {9};

    Solution SolutionObj;
    SolutionObj.plusOne(input_vector);

    return 0;
}