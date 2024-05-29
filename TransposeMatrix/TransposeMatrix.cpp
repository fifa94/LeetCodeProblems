#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> transpose(std::vector<std::vector<int>> &matrix)
    {
        std::vector<std::vector<int>> result;
        std::vector<int> row;
        int col = 0;

        while (col < matrix[0].size())
        {
            for (int i = 0; i < matrix.size(); i++)
            {
                row.push_back(matrix[i][col]);
            }
            result.push_back(row);
            row.clear();
            col++;
        }

        return result;
    }
};

int main()
{
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},};

    Solution SolutionObj;
    SolutionObj.transpose(matrix);

    return 0;
}