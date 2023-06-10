#include <vector>
#include <algorithm>
#include <iostream>

class Solution
{
public:
    char nextGreatestLetter(std::vector<char> &letters, char target)
    {
        int distance_old = 0;

        if((int) target != 122)
            distance_old = 999;

        char result;

        std::for_each(letters.begin(), letters.end(), [&](char &letter)
                      {
                          if ((((int)letter) < ((int)target)) && ((int)target) == 122)
                          {
                            if ((((int)letter) - (int)target) != distance_old)
                            {
                                distance_old = std::max(((int)letter) - (int)target, distance_old);
                                result = letter;
                            }
                          }
                          else if (((int)letter) >= ((int) target))
                          {
                            if ((((int)letter) - (int)target) != distance_old)
                            {
                                if (distance_old > ((int)letter - (int)target))
                                {
                                    distance_old = (int)letter - (int)target;
                                    result = letter;
                                }
                                
                                //distance_old = std::min(((int)letter) - (int)target, distance_old);
                                //result = letter;
                            }
                          }
                      });
        return result;
    }
};

int main()
{
    std::vector<char> letters{'c', 'f', 'j'};
    char target{'c'};

    Solution SolutionObj;
    std::cout << SolutionObj.nextGreatestLetter(letters, target);
    return 0;
}