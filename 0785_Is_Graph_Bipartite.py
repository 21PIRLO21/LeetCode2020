from typing import List

''' Medium '''
# 并查集
# class Solution:
#     def isBipartite(self, graph: List[List[int]]) -> bool:

class UFS:
    # 初始化p数组记录父节点，rank数组记录节点深度
    def __init__(self, length):
        self.p = [i for i in range(length)]
        self.rank = [0] * length
    
    # 查找根节点
    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    # 合并两个节点
    def union(self, x, y):
        rx, ry = self.find(x), self.find(y)
        if self.rank[rx] < self.rank[ry]:
            self.p[rx] = ry
        elif self.rank[rx] > self.rank[ry]:
            self.p[ry] = rx
        else:
            self.p[rx] = ry
            self.rank[ry] += 1

class Solution_1:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        ufs = UFS(len(graph))
        for i, g in enumerate(graph):
            root = ufs.find(i)
            # 若对面节点的根节点和当前节点根节点相同，返回False
            for j in range(len(g)):
                if root == ufs.find(g[j]):
                    return False
            # 否则就把对面节点都合并起来
            for j in range(1, len(g)):
                ufs.union(g[j - 1], g[j])
        return True

# the fastest
class Solution_2:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        color = {}
          
        for vert in range(len(graph)):
            if vert in color:
                continue
            stack = [vert]
            color[vert] = 0
            
            while stack: 
                node = stack.pop()

                for nei in graph[node]: 
                    if nei not in color: 
                        color[nei] = color[node] ^ 1
                        stack.append(nei)
                    
                    elif color[node] == color[nei]:
                        return False
                    
                    
        return True

# DFS
class Solution_3:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        colors = [0] * len(graph)
        for i in range(len(graph)):
            if colors[i] == 0:
                if self._dfs(graph, colors, i, 1) is False:
                    return False
        return True
    
    def _dfs(self, graph, colors, v, curr_color):
        if colors[v] != 0:
            return colors[v] == curr_color
        
        colors[v] = curr_color
        for next_ in graph[v]:
            if self._dfs(graph, colors, next_, -1 * curr_color) is False:
                return False
        
        return True