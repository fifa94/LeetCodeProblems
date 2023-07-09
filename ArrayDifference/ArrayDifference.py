import itertools
class Solution:
    def findDifference(self, nums1: list[int], nums2: list[int]) -> list[list[int]]:
        nums1_set = set(nums1)
        nums2_set = set(nums2)

        result1 = []
        result2 =[]
        result = []

        for list_one_element in nums1_set:
            if list_one_element not in nums2_set:
                result1.append(list_one_element)
        for list_two_element in nums2_set:
            if list_two_element not in nums1_set:
                result2.append(list_two_element)

        result.append(result1)
        result.append(result2)
        return result


if __name__ == '__main__':
    SolutionObj = Solution()
    print(SolutionObj.findDifference([1,2,3,3], [1,1,2,2]))