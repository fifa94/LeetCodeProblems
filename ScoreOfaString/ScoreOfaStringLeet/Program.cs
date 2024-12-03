using System.Collections.Generic;
using System.Linq;
using System.Text;

public class Solution
{
    public int ScoreOfString(string s)
    {
        int score = 0;

        for (int i = 1; i < s.Length; i++)
        {
            score += Math.Abs((int)s[i] - (int)s[i - 1]);
        }
        return score;
    }
}

class SolutionMain
{
    static void Main(string[] args)
    {
        string s = "hello";
        Solution solution = new Solution();
        Console.WriteLine(solution.ScoreOfString(s));
    }
}
