from typing import List

''' Easy '''

# the fastest
# 最终结果应该是占到 2 的赢，占到 1 的输；
# 若当前为奇数，奇数的约数只能是奇数或者 1，因此下一个一定是偶数；
# 若当前为偶数， 偶数的约数可以是奇数可以是偶数也可以是 1，因此直接减 1，则下一个是奇数；

# 因此，奇则输，偶则赢
class Solution_1:
    def divisorGame(self, N: int) -> bool:
        if N % 2 == 0:
            return True
        else:
            return False

# DP
# 作者：pandawakaka
# 链接：https://leetcode-cn.com/problems/divisor-game/solution/python3gui-na-fa-by-pandawakaka/
class Solution:
    def divisorGame(self, N: int) -> bool:
        dp = [0 for i in range(N + 1)]
        dp[1] = 0 # 若爱丽丝抽到1，则爱丽丝输
        if N <= 1:
            return False
        else:
            dp[2] = 1 # 若爱丽丝抽到2，则爱丽丝赢
            for i in range(3, N + 1):
                for j in range(1, i // 2):
                    # 若j是i的余数且target[i-j]为假（0）的话，则代表当前为真（1）
                    if i % j == 0 and dp[i - j] == 0:
                        dp[i] = 1
                        break
            return dp[N] == 1
