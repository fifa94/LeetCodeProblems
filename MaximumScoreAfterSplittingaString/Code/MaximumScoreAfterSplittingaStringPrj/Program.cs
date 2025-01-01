

using System.Globalization;

public class Solution
{
    public int MaxScore(string s)
    {

        if (s == null) return 0;

        int maxScore = 0;
        int index = 1;

        while (index < s.Length)
        {
            int cntZeros = 0;
            int cntOnes = 0;
            /* zeros */
            for (int i = 0; i < index; i++)
            {
                switch (s[i])
                {
                    case '0':
                        cntZeros++;
                        break;
                }
            }
            /* ones */
            for (int x = index; x < s.Length; x++)
            {
                switch (s[x])
                {
                    case '1':
                        cntOnes++;
                        break;
                }
            }
            maxScore = Math.Max(maxScore, cntZeros + cntOnes);
            index++;
        }

        return maxScore;
    }
}

class SolutionLeet
{
    public static void Main(String[] args)
    {
        Solution solution = new Solution();
        string str = "011101";
        solution.MaxScore(str);
    }
}
