#include<vector>
#include<iostream>
#include <algorithm>


class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        
        std::vector<std::vector<int>> results;
        std::vector<int> row;

        for (int i = 0; i < rowIndex + 1; i++)
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

        return results[results.size() - 1];
    }
};

int main()
{
    std::vector<int> res;
    Solution SolutionObj;
    res = SolutionObj.getRow(3);

    for(auto element : res)
        std::cout << element << std::endl;
    return 0;
}