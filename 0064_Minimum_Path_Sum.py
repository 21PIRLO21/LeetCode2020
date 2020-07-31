from typing import List

''' Medium '''
class Solution_1:
    def minPathSum(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0
        m = len(grid)
        n = len(grid[0])
        table = [[0 for _ in range(n + 1)] for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if i == 1:
                    table[i][j] = table[1][j - 1] + grid[0][j - 1]
                elif j == 1:
                    table[i][j] = table[i - 1][1] + grid[i - 1][0]
                else:
                     table[i][j] = min(table[i - 1][j], table[i][j - 1]) + grid[i - 1][j - 1]
        return table[-1][-1]

class Solution_2:
    def minPathSum(self, grid: List[List[int]]) -> int:
        if not grid or not grid[0]:
            return 0
        
        rows, columns = len(grid), len(grid[0])
        dp = [[0] * columns for _ in range(rows)]
        dp[0][0] = grid[0][0]
        for i in range(1, rows):
            dp[i][0] = dp[i - 1][0] + grid[i][0]
        for j in range(1, columns):
            dp[0][j] = dp[0][j - 1] + grid[0][j]
        for i in range(1, rows):
            for j in range(1, columns):
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]
        
        # return dp[rows - 1][columns - 1]
        return dp[-1][-1]