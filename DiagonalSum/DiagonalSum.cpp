#include <vector>
#include <iostream>

class Solution {
public:
    int diagonalSum(std::vector<std::vector<int>>& mat) {
        
        int diagonal_sum = 0;

        for (int i = 0; i < mat.size(); i++)
        {
            if (i!= ((mat.size() - 1) - i))
            {
                diagonal_sum += (mat[i][i] + mat[i][(mat.size() - 1) - i]);
            }
            else{
                diagonal_sum += mat[i][i];
            }

        }

        return diagonal_sum;
    }
};

int main()
{

    std::vector<std::vector<int>> mat = {{1,2,3},{4,5,6}, {7,8,9}};
    Solution SolutionObj;
    std::cout<<SolutionObj.diagonalSum(mat);

    return 0;
}