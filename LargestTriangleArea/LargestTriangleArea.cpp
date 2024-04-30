#include <vector>
#include <iostream>
#include <math.h>
class Solution
{
public:
   constexpr double largestTriangleArea(std::vector<std::vector<int>> &points)
    {
        double max_area = 0;
        for (int i = 0; i < points.size(); i++)
        {
            for (int j = i + 1; j < points.size(); j++)
            {
                for (int k = j + 1; k < points.size(); k++)
                {
                    const double area = 0.5 * abs(points[i][0] * points[j][1] + points[j][0] * points[k][1] + points[k][0] * points[i][1] - points[j][0] * points[i][1] - points[k][0] * points[j][1] - points[i][0] * points[k][1]);
                    if (area > max_area)
                    {
                        max_area = area;
                    }
                }
            }
        }

        return max_area;
    }
};

int main()
{

    std::vector<std::vector<int>> points = {{4, 6}, {6, 5}, {3, 1}};
    Solution SolutionObj;
    std::cout << SolutionObj.largestTriangleArea(points);
    return 0;
}