#include <vector>
#include <iostream>
#include <bits/stdc++.h>

class Solution
{
public:
    std::vector<int> dailyTemperatures(std::vector<int> &temperatures)
    {
        std::vector<int> result;

        // Initialise stack
        std::stack<int> stk;

        for (int i = 0; i < temperatures.size(); i++)
        {

            // Either stack is empty or
            // all bigger nums are popped off
            while (stk.size() > 0 && stk.top() > temperatures[i])
            {
                stk.pop();
            }
            stk.push(temperatures[i]);
        }
    }
};

int main()
{
    std::vector<int> temperature{73, 74, 75, 71, 69, 72, 76, 73};
    Solution SolutionObj;
    SolutionObj.dailyTemperatures(temperature);

    return 0;
}

/*
[1,1,4,2,1,1,0,0]
*/