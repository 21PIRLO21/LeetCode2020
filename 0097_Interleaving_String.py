from typing import List

''' Hard '''
class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        m, n = len(s1), len(s2)
        if m + n != len(s3):
            return False
        
        # 初始化dp 包括第一行和第一列
        dp = [[False]*(n+1) for _ in range(m+1)]
        dp[0][0] = True
        for i in range(1,m+1): # 初始化第一列
            dp[i][0] = dp[i-1][0] and (s3[i-1] == s1[i-1])
        for i in range(1,n+1): # 初始化第一行
            dp[0][i] = dp[0][i-1] and (s3[i-1] == s2[i-1])

        # 计算所有dp值
        for i in range(1,m+1):
            for j in range(1,n+1):
                # 状态转移方程，核心
                dp[i][j] = (dp[i-1][j] and (s3[i+j-1] == s1[i-1])) or (dp[i][j-1] and (s3[i+j-1] == s2[j-1]))
                
        return dp[-1][-1]