class Solution:
    def shuffle(self, nums: list[int], n: int) -> list[int]:

        first_list = []
        second_list = []
        result_list = []

        for index in range(len(nums)):
            if index < n:
                first_list.append(nums[index])
            else:
                second_list.append(nums[index])

        for index in range (len(first_list)):
            result_list.append(first_list[index])
            if index < len(second_list):
                result_list.append(second_list[index])

        return result_list



if __name__ == '__main__':

    SolutionObj = Solution()
    print(SolutionObj.shuffle([2, 5, 1, 3, 4, 7], 3))
