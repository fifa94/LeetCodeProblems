class Solution:
    def romanToInt(self, s: str) -> int:

        roman_dict = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        next_val = result = int_value = 0

        for char in range(len(s)):
            if s[char] in roman_dict:
                int_value = roman_dict[s[char]]

                if char < (len(s)-1):
                    next_val = roman_dict[s[char + 1]]

                if int_value < next_val:
                    result -= int_value
                else:
                    result += int_value
        return result


if __name__ == '__main__':
        SolutionObj = Solution()
        print(SolutionObj.romanToInt('MCMXCIV'))