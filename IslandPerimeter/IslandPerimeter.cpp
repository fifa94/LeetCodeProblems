#include <vector>
#include <iostream>

class Solution
{
public:
    int islandPerimeter(std::vector<std::vector<int>> &grid)
    {
        int perimeter = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int x = 0; x < grid[i].size(); x++)
            {
                if (grid[i][x] == 1)
                {

                    perimeter += 4;

                    /* left */
                    if ((x - 1) >= 0)
                    {
                        if (grid[i][x - 1] == 1)
                        {
                            perimeter--;
                        }
                    }

                    /* right */
                    if ((x + 1) < grid[i].size())
                    {
                        if (grid[i][x + 1] == 1)
                        {
                            perimeter--;
                        }
                    }
                    /* up */
                    if ((i - 1) >= 0)
                    {
                        if (grid[i - 1][x] == 1)
                        {
                            perimeter--;
                        }
                    }
                    /* down */
                    if ((i + 1) < grid.size())
                    {
                        if (grid[i + 1][x] == 1)
                        {
                            perimeter--;
                        }
                    }
                }
            }
        }
        return perimeter;
    }
};

int main()
{
    std::vector<std::vector<int>> grid = {{1, 0}};
    Solution SolutionObj;
    std::cout << SolutionObj.islandPerimeter(grid);

    return 0;
}