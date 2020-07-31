from typing import List

''' Medium '''

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution_1:
    def __init__(self):
        self.maps = {}

    def generateTrees(self, n):
        if n < 1: return []
        return self.helper(1, n)
    
    def helper(self, s, e):
        if (s,e) in self.maps:
            return self.maps[(s,e)]
        res = []
        if s > e:
            res.append(None)
            return res
        for i in range(s, e + 1):
            left = self.helper(s, i - 1)
            right = self.helper(i + 1, e)
            for L in left:
                for R in right:
                    root = TreeNode(i)
                    root.left = L
                    root.right = R
                    res.append(root)
        self.maps[(s,e)] = res
        return res

class Solution_2:
    def generateTrees(self, n: int) -> List[TreeNode]:
        if n == 0:
            return []
        dct = {}

        def left_right(left: int, right: int) -> List[TreeNode]:
            if left > right:
                return [None]
            if (left, right) in dct:
                return dct[(left, right)]
            ret = []
            for i in range(left, right+1):
                left_lst = left_right(left, i-1)
                right_lst = left_right(i+1, right)
                for L in left_lst:
                    for R in right_lst:
                        app_Tree = TreeNode(i)
                        app_Tree.left = L
                        app_Tree.right = R
                        ret.append(app_Tree)
            dct[(left, right)] = ret
            return ret

        # left_right(1, n)
        return left_right(1, n)

# the fastest
class Solution_3:
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        def generate_trees(start, end):
            if start > end:
                return [None,]
            
            all_trees = []
            for i in range(start, end + 1):  # pick up a root
                # all possible left subtrees if i is choosen to be a root
                left_trees = generate_trees(start, i - 1)
                
                # all possible right subtrees if i is choosen to be a root
                right_trees = generate_trees(i + 1, end)
                
                # connect left and right subtrees to the root i
                for l in left_trees:
                    for r in right_trees:
                        current_tree = TreeNode(i)
                        current_tree.left = l
                        current_tree.right = r
                        all_trees.append(current_tree)
            
            return all_trees
        
        return generate_trees(1, n) if n else []