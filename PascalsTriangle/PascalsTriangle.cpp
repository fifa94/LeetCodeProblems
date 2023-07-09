#include <vector>
#include <iostream>

class Solution
{
public:
    std::vector<std::vector<int>> generate(int numRows)
    {
        std::vector<std::vector<int>> results;
        std::vector<int> row;

        for (int i = 0; i < numRows; i++)
        {
            row.push_back(1);
            
            if (i > 1)
            {
                for (int x = 1; x < results[i - 1].size() + 1; x++)
                {
                    if (x < results[i - 1].size())
                    {
                        row.push_back(results[i - 1][x - 1] + results[i - 1][x]);
                    }
                    else if (results[i - 1].size() + 1)
                    {
                       row.push_back(1);
                    }
                }
            }
            else if(i == 1)
            {
               row.push_back(1); 
            }

        
            results.push_back(row);
            row.clear();
        }

        return results;
    }
};

int main()
{
    Solution SolutionObj;
    SolutionObj.generate(5);
    return 0;
}