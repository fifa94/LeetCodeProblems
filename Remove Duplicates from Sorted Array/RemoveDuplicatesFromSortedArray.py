class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        nums_set = set()
        i = 0

        while (i<len(nums)):
        
            if nums[i] in nums_set:
                nums.remove(nums[i])
            else:
                nums_set.add(nums[i])
                i += 1

        return len(nums_set)
    

    #def removeDuplicates(self, nums: list[int]) -> int:
    #    char = set()
    #    p = 0
    #    while(p<len(nums)):
    #        if(nums[p] in char):
    #            nums.remove(nums[p])
    #        else:
    #            char.add(nums[p])
    #            p = p+1
                
    #    #print(nums)
    #    return len(char)

if __name__ == '__main__':

    SolutionObj = Solution()
    print(SolutionObj.removeDuplicates([1,1,2]))