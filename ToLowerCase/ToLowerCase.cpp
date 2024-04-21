#include <string>
#include <iostream>

class Solution {
public:
    std::string toLowerCase(std::string s) {

        for (int i = 0; i < s.size(); i++)
        {
            if (((int)s[i] >= 65) && ((int)s[i] <= 90))
            {
                s[i] = s[i] + 32;
            }
        }
        return s;
    }
};


int main() {
    std::string s = "Hello";
    Solution SolutionObj;
    SolutionObj.toLowerCase(s);
    return 0;
}