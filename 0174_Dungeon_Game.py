''' Hard '''
# 借助辅助dp数组
class Solution_1:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:  
        if not dungeon or not dungeon[0]:
            return 0
        rows, cols = len(dungeon), len(dungeon[0])
        # box = 1
        BIG = 10**9
        
        dp = [[BIG] * (cols + 1) for _ in range(rows + 1)]
        dp[rows][cols - 1] = dp[rows - 1][cols] = 1
        
        for x in range(rows - 1, -1, -1): # (-1, rows - 1] == [0, rows - 1]
            for y in range(cols - 1, -1, -1):
                # box--走下一步之前血槽最少要有多少血
                box = min(dp[x + 1][y], dp[x][y + 1])
                # dp[x][y]--走到坐标(x, y)想存活的话，上一步应含血量值
                dp[x][y] = max(1, box - dungeon[x][y])

        return dp[0][0]

# the fastest
class Solution_2:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        x = len(dungeon)
        y = len(dungeon[0])
        dp = [[None for __ in range(y)] for __ in range(x)]
        # 先填充最后一格
        dp[-1][-1] = 1 if dungeon[-1][-1] >= 0 else -dungeon[-1][-1]+1
        # 填充最后一列
        for i in range(x-2, -1, -1):
            tmp = dp[i+1][-1]-dungeon[i][-1]
            dp[i][-1] = 1 if tmp <= 0 else tmp
        # 填充最后一行
        for i in range(y-2, -1, -1):
            tmp = dp[-1][i+1]-dungeon[-1][i]
            dp[-1][i] = 1 if tmp <= 0 else tmp
        # 填充其他
        for i in range(x-2, -1, -1):
            for j in range(y-2, -1, -1):
                tmp = min(dp[i][j+1], dp[i+1][j])-dungeon[i][j]
                dp[i][j] = 1 if tmp <= 0 else tmp

        return dp[0][0]