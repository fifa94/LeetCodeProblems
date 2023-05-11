#include <string>
#include <string.h>
#include <iostream>

#include <string>
#include <string.h>
#include <iostream>

class Solution
{
public:
    bool isAnagram(std::string s, std::string t)
    {

        if (s.size() == t.size())
        {

            int ascii_sum_s = 0;
            int ascii_sum_t = 0;

            for (int i = 97; i < 122; i++)
            {
                ascii_sum_s = 0;
                ascii_sum_t = 0;

                for (int x = 0; x < t.length(); x++)
                {
                    std::cout << " s " << int(s[x]) ;
                    std::cout << " i " << i << std::endl;
                    //(int(s[x]) == i) ? : ascii_sum_s += 0;
                    if (int(s[x]) == i)
                    {
                        ascii_sum_s += 1;
                    }
                    else
                    {
                        ascii_sum_s += 0;
                    }

                    if (int(t[x]) == i)
                    {
                        ascii_sum_t += 1;
                    }
                    else
                    {
                        ascii_sum_t += 0;
                    }
                    //(int(t[x]) == i) ? ascii_sum_t += 1 : ascii_sum_t += 0;
                    // ascii_sum_s += int(s[x]) == i;
                    // ascii_sum_t += int(t[x]) == i;
                }

                if (ascii_sum_s != ascii_sum_t)
                {
                    return 0;
                }
            }

            return 1;
        }
        return 0;
    }
};

int main()
{

    Solution SolutionObj;
    std::cout << SolutionObj.isAnagram("anagtam", "nbgbram");

    return 0;
}