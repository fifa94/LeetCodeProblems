
public class Solution {
    public bool RotateString(string s, string goal) {

        if (s == null) {
            return false;
        }

        if (s == goal) {
            return true;
        }

        List<char> list_s = new List<char>(s.ToCharArray().ToList());
        List<char> list_goal = new List<char>(goal.ToCharArray().ToList());
        
        for (int i = 0; i < list_s.Count; i++) {
            char first = list_s[0];
            list_s.RemoveAt(0);
            list_s.Add(first);
            if (list_s.SequenceEqual(list_goal)) {
                return true;
            }
        }
        
        return false;
    }
}

class SolutionLeetcode
{

    static void Main(string[] args)
    {
        Solution solution = new Solution();

        // Testovací řetězce
        string s = "abcde";
        string goal = "cdeab";

        // Volání metody a výstup výsledku
        bool result = solution.RotateString(s, goal);
        Console.WriteLine("Výsledek rotace: " + result);  // Očekává true

    }
}