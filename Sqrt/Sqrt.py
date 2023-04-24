# Press the green button in the gutter to run the script.
class Solution:

    def mySqrt(self, x: int) -> int:

        xk1 = 0
        xk = x
        a = x
        if x > 0:
            for iteration in range(20):
                xk1 = 0.5 * (xk + (a / xk))
                xk = xk1
                print('Xk+1: ', xk1)

        return int(xk1)


if __name__ == '__main__':

    SolutionObj = Solution()
    print (SolutionObj.mySqrt(2147395599))

