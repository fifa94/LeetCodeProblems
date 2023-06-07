#include <vector>
#include <iostream>

class Solution
{
public:
    int buyChoco(std::vector<int> &prices, int money)
    {
        int result = 0;

        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < money)
            {
                for (int x = i + 1; x < prices.size(); x++)
                {
                    int value = prices[i];
                    int value1 = prices[x];
                    
                    if ((result == 0) && ((prices[i] + prices[x]) <= money))
                    {
                        result = (prices[i] + prices[x]);
                    }
                    
                    if (((prices[i] + prices[x]) <= money) && ((prices[i] + prices[x]) > 0) && ((prices[i] + prices[x]) < result))
                    {
                        result = (prices[i] + prices[x]);
                    }
                }
            }
        }
        return money - result;
    }
};

int main()
{
    Solution SolutionObj;
    //std::vector<int> prices{98, 54, 6, 34, 66, 63, 52, 39};
    //std::cout << SolutionObj.buyChoco(prices, 62);
    std::vector<int> prices{1, 2, 2};
    //std::vector<int> prices{3, 2, 3};
    std::cout << SolutionObj.buyChoco(prices, 3);
    
    return 0;
}