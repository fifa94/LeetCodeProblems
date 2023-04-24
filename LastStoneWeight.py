class Solution:
    def lastStoneWeight(self, stones: list[int]) -> int:

        sorted_weights = sorted(stones)
        sorted_weights.reverse()

        print(sorted_weights)

        condition = True

        if len(sorted_weights) > 2:

            while condition == True:

                sorted_weights = sorted(sorted_weights)
                sorted_weights.reverse()

                if len(sorted_weights) == 1:
                    condition = False
                    break
                elif len(sorted_weights) == 0:
                    condition = False
                    return 0
                    break

                if (sorted_weights[0] != sorted_weights[1]) & (len(sorted_weights) > 1):
                    new_weight = sorted_weights[0] - sorted_weights[1]
                    sorted_weights.append(new_weight)

                for i in range(2):
                    print(sorted_weights[0])
                    sorted_weights.remove(sorted_weights[0])

                print('len: ', len(sorted_weights))
                print(sorted_weights)
        else:

            if len(sorted_weights) == 1:
                return sorted_weights[0]

            sorted_weights[0] = sorted_weights[0] - sorted_weights[1]

        return sorted_weights[0]


if __name__ == '__main__':

    SolutionObj = Solution()
    print(SolutionObj.lastStoneWeight([2, 2]))
