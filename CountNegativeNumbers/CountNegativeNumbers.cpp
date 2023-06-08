#include <vector>
#include <iostream>
#include <algorithm>


class Solution {
public:
    int countNegatives(std::vector<std::vector<int>>& grid) {

        int count = 0;
        /*
        //std::cout << grid.size();
        for (int i = 0; i < grid.size(); i++)
        {
            std::for_each(grid[i].begin(), grid[i].end(),[&count] (int i) { if (i < 0) count +=1;});
        }
        */

        std::for_each(grid.begin(), grid.end(), [&](const std::vector<int>& sub_vector) {
            std::for_each(sub_vector.begin(), sub_vector.end(), [&](int i){
                if (i < 0)
                    count += 1;
            });
        });
        
       return count;
    }
};

int main()
{
    std::vector<std::vector<int>> grid {{4,3,2,-1}, {3,2,1,-1}, {1,1,-1,-2}, {-1,-1,-2,-3}};
    Solution SolutionObj;
    std::cout<< SolutionObj.countNegatives(grid);
}