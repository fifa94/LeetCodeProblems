#include <iostream>
#include<math.h>

class Solution
{
public:
    int addDigits(int num)
    {

        if (num > 9)
        {
            int num_check = 0;
            int num_copy = num;
            int digit = 0;
            int sum = 0;
            int i = 1;

            do
            {
                digit = 0;

                if (num_check != num)
                {
                    unsigned int pow_val = (int)pow(10, i);
                    digit = (unsigned int)num  % (pow_val);
                    num_check = digit;
                    digit = digit / (pow_val / 10);
                    sum += digit;
                }
                else
                {
                    i = 0;
                    num_check = 0;
                    num = sum;
                    sum = 0;
                }

                i++;

            } while (num >= 10);
        }
        return num;
    }
};

int main()
{

    Solution SolutionObj;
    std::cout << SolutionObj.addDigits(2032610959);

    return 0;
}