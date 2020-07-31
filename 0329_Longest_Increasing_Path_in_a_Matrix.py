from typing import List
import collections

''' Hard '''
# 记忆化+深度优先搜索
# 作者：ting-ting-28
# 链接：https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/solution/python3-shen-du-you-xian-sou-suo-ji-yi-hua-di-gui-/
class Solution_1:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        if not matrix:
            return 0
        nxt = ((1, 0), (-1, 0), (0, -1), (0, 1))
        old = {}
        matrix = [[float("inf")]+i+[float("inf")] for i in matrix]
        col = len(matrix[0])
        matrix = [[float("inf")]*col]+matrix+[[float("inf")]*col]
        row = len(matrix)

        def maxIncreasingRoute(x: int, y: int) -> int:
            if (x, y) in old:
                return old[(x, y)]
            if x in {0, row-1} or y in {0, col-1}:
                return 0
            old[(x, y)] = 1+max([0]+[maxIncreasingRoute(x+xx, y+yy) for xx, yy in nxt if matrix[x][y] < matrix[x+xx][y+yy]])
            return old[(x, y)]

        return max([maxIncreasingRoute(i, j) for j in range(1, col-1) for i in range(1, row-1)])

# 拓扑排序
# 作者：LeetCode-Solution
# 链接：https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/solution/ju-zhen-zhong-de-zui-chang-di-zeng-lu-jing-by-le-2/
class Solution:
    DIRS = [(-1, 0), (1, 0), (0, -1), (0, 1)]

    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        if not matrix:
            return 0
        
        rows, columns = len(matrix), len(matrix[0])
        outdegrees = [[0] * columns for _ in range(rows)]
        queue = collections.deque()
        for i in range(rows):
            for j in range(columns):
                for dx, dy in Solution.DIRS:
                    newRow, newColumn = i + dx, j + dy
                    if 0 <= newRow < rows and 0 <= newColumn < columns and matrix[newRow][newColumn] > matrix[i][j]:
                        outdegrees[i][j] += 1
                if outdegrees[i][j] == 0:
                    queue.append((i, j))

        ans = 0
        while queue:
            ans += 1
            size = len(queue)
            for _ in range(size):
                row, column = queue.popleft()
                for dx, dy in Solution.DIRS:
                    newRow, newColumn = row + dx, column + dy
                    if 0 <= newRow < rows and 0 <= newColumn < columns and matrix[newRow][newColumn] < matrix[row][column]:
                        outdegrees[newRow][newColumn] -= 1
                        if outdegrees[newRow][newColumn] == 0:
                            queue.append((newRow, newColumn))
        
        return ans

# sum(dp, [])，没想到sum还能用来合并二维数组到一维，学到了。
# ([cui]可以用 list.extend() + for循环 实现同样的效果)
# >>> matrix=[[1,2,3],[4,5,6],[7,8,9]]
# >>> matrix
# [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
# >>> x, y = len(matrix), len(matrix[0])
# >>> x, y
# (3, 3)
# >>> b = [[(matrix[i][j], i, j) for j in range(y)] for i in range(x)]
# [[(1, 0, 0), (2, 0, 1), (3, 0, 2)], [(4, 1, 0), (5, 1, 1), (6, 1, 2)], [(7, 2, 0), (8, 2, 1), (9, 2, 2)]]
# >>> sum(b, [])
# [(1, 0, 0), (2, 0, 1), (3, 0, 2), (4, 1, 0), (5, 1, 1), (6, 1, 2), (7, 2, 0), (8, 2, 1), (9, 2, 2)]
# >>>