class Solution {
public:
    double myPow(double x, int n) {
        if (x != 0)
        {
          if (n < 0)
          {
            n = -n;
            x = 1 / x;
          }
            
        }

        return 1;
    }
};

int main ()
{
    Solution SolutionObj;
    SolutionObj.myPow(2, 2);
    return 0;
}