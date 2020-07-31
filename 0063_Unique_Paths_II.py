''' Medium '''
# 原地操作
class Solution_1:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        # DP, 直接在原矩阵上更改, 节省空间
        if not obstacleGrid:
            return 0
        rows, cols = len(obstacleGrid), len(obstacleGrid[0])
        for r in range(rows):
            for c in range(cols):
                if obstacleGrid[r][c] == 0:
                    if r == 0 and c == 0:
                        # 初始起点为1(如果没有障碍物的情况下)
                        obstacleGrid[r][c] = 1
                    else:
                        left = obstacleGrid[r][c - 1] if c > 0 else 0
                        up = obstacleGrid[r - 1][c] if r > 0 else 0
                        obstacleGrid[r][c] = left + up
                else:
                    obstacleGrid[r][c] = 0
        return obstacleGrid[rows - 1][cols - 1]      

# 额外打表格
class Solution_2:
    def uniquePathsWithObstacles(self, obstacleGrid) -> int:
        if not obstacleGrid or not obstacleGrid[0] or obstacleGrid[0][0]:
            return 0
        dp = [[0 for y in obstacleGrid[0]] for x in obstacleGrid]
        dp[0][0] = 1
        for x in range(len(obstacleGrid)):
            for y in range(len(obstacleGrid[0])):
                if obstacleGrid[x][y] or (x,y) == (0,0):
                    continue
                dp[x][y] = dp[x-1][y] + dp[x][y-1]
        print(dp)
        return dp[-1][-1]