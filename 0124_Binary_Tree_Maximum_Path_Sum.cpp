#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/* Hard */
/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (root == nullptr) {
            return max_sum;
        }
        DFS(root);
        return max_sum;
    }
    //后序遍历树，返回经过root的单边最大路径和，并维护整棵树的最大路径和
    int DFS(TreeNode *root) {
        if (root == nullptr) return 0;
        
        //深度优先，获取左右分支各自的最大路径和
        int l_MaxSum = max(0, DFS(root->left));
        int r_MaxSum = max(0, DFS(root->right));
        
        //由于路径最大的一种可能为left->root->right，而不向root的父结点延伸
        int lnr_sum = l_MaxSum + root->val + r_MaxSum;
        //与lnr_sum比较更新最大值，全是负数结点的情况，也会在这里更新最大的负数
        max_sum = max(lnr_sum, max_sum);
        
        //向root的父结点返回经过root的单边分支的最大路径和
        int branch_MaxSum = root->val + max(l_MaxSum, r_MaxSum);
        
        return branch_MaxSum;
    } 
private:
    int max_sum = INT_MIN;
};