#include <iostream>

class Solution{
    public:
    bool isUgly(int n){

        if (n == 0)
        {
            return 0;
        }
        else if (n == 1)
        {
            return 1;
        }
        
        return isUgluAux(n);
    }
    int isUgluAux (int n){

        if(n == 1) return 1;

        if (((n % 5) == 0) && (n > 0))
        {
            return isUgluAux(n / 5);
        }
        else if (((n % 3) == 0) && (n > 0))
        {
            return isUgluAux(n / 3);
        }
        else if (((n % 2) == 0) && (n > 0))
        {
            return isUgluAux(n / 2);
        }

        return 0;
    }
};

int main()
{
    int n = 6;
    Solution SolutionObj;
    std::cout << SolutionObj.isUgly(n);
    return 0;
}