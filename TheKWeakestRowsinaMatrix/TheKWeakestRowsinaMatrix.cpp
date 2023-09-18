#include <iostream>
#include <vector>
#include <algorithm>


class Solution
{
public:
    std::vector<int> kWeakestRows(std::vector<std::vector<int>> &mat, int k)
    {
        std::vector<std::pair<int, int>> histogram;
        std::vector<int> results;
        int sum;
        for (int i = 0; i < mat.size(); i++)
        {
            sum = 0;
            for (int x = 0; x < mat[i].size(); x++)
            {
                sum = sum + mat[i][x];
            }
            std::cout << "sum " << sum << std::endl;
            histogram.push_back(std::make_pair(sum, i));
            
        }
    
        std::sort(histogram.begin(), histogram.end());
        for (int i = 0; i < k; i++)
        {
            results.push_back(histogram[i].first);
        }

        return results;
    }
};
int main()
{
    int k = 3;
    std::vector<std::vector<int>> mat{{1, 1, 0, 0, 0}, {1, 1, 1, 1, 0}, {1, 0, 0, 0, 0}, {1, 1, 0, 0, 0}, {1, 1, 1, 1, 1}};

    Solution SolutionObj;
    SolutionObj.kWeakestRows(mat, k);
}