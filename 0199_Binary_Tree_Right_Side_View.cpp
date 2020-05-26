#include <ostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

/* medium */
/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// DFS
class Solution_1 {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> res;
        levelOrder(root, 0, res);

        vector<int> ans;
        for (int i = 0; i < res.size(); ++i) {
            ans.push_back(res[i][0]);
        }

        return ans;
    }

    void levelOrder(TreeNode* root, int level, vector<vector<int>>& res) {
        if (root == nullptr)    return;
        if (res.size() == level)    res.resize(level + 1);
        res[level].push_back(root->val);
        levelOrder(root->right, level + 1, res);
        levelOrder(root->left, level + 1, res);
    }
};

// BFS
class Solution_2 {
public:
    vector<int> rightSideView(TreeNode* root) {
        unordered_map<int, int> rightmostValueAtDepth;
        int max_depth = -1;

        queue<TreeNode*> nodeQueue;
        queue<int> depthQueue;
        nodeQueue.push(root);
        depthQueue.push(0);

        while (!nodeQueue.empty()) {
            TreeNode* node = nodeQueue.front();nodeQueue.pop();
            int depth = depthQueue.front();depthQueue.pop();

            if (node != NULL) {
            	// 维护二叉树的最大深度
                max_depth = max(max_depth, depth);

                // 由于每一层最后一个访问到的节点才是我们要的答案，因此不断更新对应深度的信息即可
                rightmostValueAtDepth[depth] =  node -> val;

                nodeQueue.push(node -> left);
                nodeQueue.push(node -> right);
                depthQueue.push(depth + 1);
                depthQueue.push(depth + 1);
            }
        }

        vector<int> rightView;
        for (int depth = 0; depth <= max_depth; ++depth) {
            rightView.push_back(rightmostValueAtDepth[depth]);
        }

        return rightView;
    }
};