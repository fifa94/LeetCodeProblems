class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        return num + 2*t;
    }
};

int main ()
{
    Solution SolutionObj;
    SolutionObj.theMaximumAchievableX(3, 2);
    return 0;
}