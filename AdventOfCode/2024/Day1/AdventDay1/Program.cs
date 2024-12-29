using System;
using System.IO;
using System.Text;

class Solution
{
    string _path;
    List<int> numbersLeft = new List<int>();
    List<int> numbersRight = new List<int>();
    public Solution(string path) => _path = path;
    public bool loadFile()
    {
        if (_path == null)
        {
            throw new ArgumentNullException("path");
        }

        using (StreamReader sr = new StreamReader(_path))
        {
            string line;
            while ((line = sr.ReadLine()) != null)
            {
                string[] parts = line.Split(' ', StringSplitOptions.RemoveEmptyEntries);
                numbersLeft.Add(int.Parse(parts[0]));
                numbersRight.Add(int.Parse(parts[1]));
                
            }
            sr.Close();
        }
        return true;
    }

    public int getDistance()
    {
        int distance = 0;
        
        numbersLeft.Sort();
        numbersRight.Sort();

        for(int i = 0; i < numbersLeft.Count; i++)
        {
            distance = distance + Math.Abs(numbersLeft[i] - numbersRight[i]);
        }

        return distance;
    }
}
class SolutionMain
{
    public static void Main(String[] args)
    {
        string path = "/home/filip/Documents/LeetCodeProblems/AdventOfCode/2024/Day1/Data.txt";
        Solution AdventDay1 = new Solution(path);
        AdventDay1.loadFile();
        AdventDay1.getDistance();

    }
}

