''' Medium '''
# dp
class Solution_1:
    def numTrees(self, n: int) -> int:
        res = [0] * (n + 1)
        res[0] = 1
        res[1] = 1
        for i in range(2, n + 1):
            for j in range(i):
                res[i] += res[i - j - 1] * res[j]
            # for j in range(1, i+1):
            #     res[i] += res[i - j] * res[j - 1]
        
        return res[n]

# 卡塔兰数
# 作者：LeetCode-Solution
# 链接：https://leetcode-cn.com/problems/unique-binary-search-trees/solution/bu-tong-de-er-cha-sou-suo-shu-by-leetcode-solution/
class Solution_2(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        C = 1
        for i in range(0, n):
            C = C * 2*(2*i+1)/(i+2)
        return int(C)