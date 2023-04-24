class Solution:
    def leftRigthDifference(self, nums: list[int]) -> list[int]:

        # right sum

        right_sum_list = []
        result_list = []
        left_sum_list = []

        for index in range(len(nums)):

            right_sum = 0

            for sub_index in range(index + 1, len(nums)):

                if index == (len(nums) - 1):
                    break

                right_sum = right_sum + nums[sub_index]

            right_sum_list.append(right_sum)

        # left sum

        for index in reversed(range(len(nums))):

            left_sum = 0

            if index == 0:
                left_sum_list.append(left_sum)
                break

            for sub_index in reversed(range(0, index)):

                left_sum = left_sum + nums[sub_index]

            left_sum_list.append(left_sum)

        left_sum_list.reverse()

        for index in range(len(right_sum_list)):
            result_list.append(abs(left_sum_list[index] - right_sum_list[index]))

        return result_list



if __name__ == '__main__':
    SolutionObj = Solution()
    print(SolutionObj.leftRigthDifference([1]))
