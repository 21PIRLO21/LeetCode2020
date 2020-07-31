''' Medium '''

class Solution_1:
    def integerBreak(self, n: int) -> int:
        if n <= 3: return n - 1
        a, b = n // 3, n % 3
        if b == 0: return int(math.pow(3, a))
        if b == 1: return int(math.pow(3, a - 1) * 4)
        return int(math.pow(3, a) * 2)

# the fastest
# DP
class Solution_2:
    def integerBreak(self, n: int) -> int:
        if n < 4:
            return n-1
        dp = [0, 1, 2, 3] + [0] * (n-3)
        for i in range(4, n+1):
            dp[i] = max(dp[j]*dp[i-j] for j in range(1, i))
        return dp[-1]