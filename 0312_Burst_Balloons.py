from typing import List

''' Hard '''
# DP
class Solution_1:
    def maxCoins(self, nums: List[int]) -> int:
        n = len(nums)
        rec = [[0] * (n + 2) for _ in range(n + 2)]
        val = [1] + nums + [1]

        for i in range(n - 1, -1, -1):
            for j in range(i + 2, n + 2):
                for k in range(i + 1, j):
                    total = val[i] * val[k] * val[j]
                    total += rec[i][k] + rec[k][j]
                    rec[i][j] = max(rec[i][j], total)
        
        return rec[0][n + 1]

# the fastest
class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        nums = [1] + [i for i in nums if i > 0] + [1]
        dp = [[0] * len(nums) for _ in range(len(nums))]
        for i in range(len(nums) - 2, -1, -1):
            for j in range(i+2, len(nums)):
                mx = 0
                for k in range(i + 1, j):
                    temp = dp[i][k] + dp[k][j] + nums[i] * nums[k] * nums[j]
                    if temp > mx:
                        mx = temp
                dp[i][j] = mx
        return dp[0][len(nums) - 1]


# 递归
class Solution_2:
    def maxCoins(self, nums: List[int]) -> int:
        n = len(nums)
        val = [1] + nums + [1]
        
        @lru_cache(None)
        def solve(left: int, right: int) -> int:
            if left >= right - 1:
                return 0
            
            best = 0
            for i in range(left + 1, right):
                total = val[left] * val[i] * val[right]
                total += solve(left, i) + solve(i, right)
                best = max(best, total)
            
            return best

        return solve(0, n + 1)