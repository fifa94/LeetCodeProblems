class Solution:
    def climbStairs(self, n: int) -> int:

        result_list = []
        result_list.append([n])
        result_cnt = 0

        for element in range(n):
            temp_list = []
            for index in range(len(result_list[element])):

                value_1 = result_list[element][index] - 1
                value_2 = result_list[element][index] - 2
                
                if value_2 == 0:
                    result_cnt = result_cnt + 1
                if value_1 == 0:
                    result_cnt = result_cnt + 1
                if value_2 > 0:
                   temp_list.append(value_2)
                   value_2 = 0
                else:
                    value_2 = 0

                if value_1 > 0:
                    temp_list.append(value_1)
                    value_1 = 0
                else:
                    value_1 = 0

            result_list.append(temp_list)
        return result_cnt


if __name__ == '__main__':
    SolutionObj = Solution()
    print(SolutionObj.climbStairs(45))