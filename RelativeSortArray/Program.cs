public class SolutionLeet
{
    public int[] RelativeSortArray(int[] arr1, int[] arr2)
    {
        var result = new int[arr1.Length];
        Dictionary<int, int> hashMap = arr2.ToDictionary(x => x, x => 0);
        List<int> numbersNotInSortingArray = new List<int>();

        for (int i = 0; i < arr1.Length; i++)
        {
            if (hashMap.ContainsKey(arr1[i]))
            {
                hashMap[arr1[i]] += 1;

            }
            else
            {
                numbersNotInSortingArray.Add(arr1[i]);
            }
        }
        
        numbersNotInSortingArray.Sort();
        int index = 0;

        for (int i = 0; i < arr2.Length; i++)
        {
            if (hashMap.TryGetValue(arr2[i], out int repeatCount))
            {
                for (int x = 0; x < repeatCount; x++)
                {
                    result[index] = arr2[i];
                    index++;
                }
            }
        }

        foreach(int value in numbersNotInSortingArray)
        {
            result[index] = value;
            index++;
        }
        
        return result;
    }
}


class Solution
{
    public static void Main(String[] args)
    {
        var arr1 = new int[] { 2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19 };
        var arr2 = new int[] { 2, 1, 4, 3, 9, 6 };

        SolutionLeet solution = new SolutionLeet();
        solution.RelativeSortArray(arr1, arr2);
    }
}