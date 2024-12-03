public class Solution {
    public string AddSpaces(string s, int[] spaces) {

        // Vytvoříme nový StringBuilder pro efektivitu
        System.Text.StringBuilder modifiedString = new System.Text.StringBuilder();

        for(int i = 0; i < spaces.Length; i++)
        {
            if (i == 0)
            {
                modifiedString.Append(s.Substring(0, spaces[i]));
                modifiedString.Append(" ");
            }
            else    
            {
                modifiedString.Append(s.Substring(spaces[i - 1], spaces[i] - spaces[i - 1] ));
                modifiedString.Append(" ");
            }
        }    
        modifiedString.Append(s.Substring(spaces[spaces.Length - 1]));
        
        return modifiedString.ToString();
    }
}

class SolutionLeetCode {
    static void Main(string[] args) {
        string s = "LeetcodeHelpsMeLearn";
        int[] spaces = {8,13,15};
        Solution solution = new Solution();
        Console.WriteLine(solution.AddSpaces(s, spaces));
    }
}