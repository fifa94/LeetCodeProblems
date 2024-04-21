#include <string>
class Solution
{
public:
    char findTheDifference(std::string s, std::string t)
    {
        int s_sum = 0;
        int t_sum = 0;
        for (int i = 0; i < s.size(); i++)
        {
            s_sum += s[i];
        }
        for (int i = 0; i < t.size(); i++)
        {
            t_sum += t[i];
        }
        return t_sum - s_sum;
    }
};

int main()
{
    std::string s = "abcd";
    std::string t = "abcde";

    Solution SolutionObj;
    SolutionObj.findTheDifference(s, t);

    return 0;
}