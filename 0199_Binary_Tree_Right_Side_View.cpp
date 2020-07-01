#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

/* Medium */
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
/* 使用层序遍历，并只保留每层最后一个节点的值 */
vector<int> rightSideView(TreeNode* root) {
	vector<int> res;
	if (!root) return res;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty())
	{
		int size = q.size(); // 这个size是核心
		res.push_back(q.front()->val);
        /* 在while（size--）里面是先temp->right 然后 temp->left,
        所以跳出这个循环后，第一个temp->right 之前的数据都pop出去了,
        所以就是剩下q.front()->val 这个数字是最右边的数字了，
        假如你是q.back()->val 不就是打印左子树嘛 */
		while (size--) // 左右子树入队顺序调换
		{
			TreeNode* temp = q.front();
			q.pop();
            // 队列q 的填装顺序是按层序 从右往左 填装
			if (temp->right) q.push(temp->right);
			if (temp->left) q.push(temp->left);
		}
	}
	return res;
}

class Solution_2 {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            res.push_back(q.back()->val);
            // while(size--)在层序遍历中的应用
            while (size--) {
                TreeNode *ptr = q.front();
                q.pop();
                // 队列q 的填装顺序是按层序 从左往右 填装
                if (ptr->left) q.push(ptr->left);
                if (ptr->right) q.push(ptr->right);
            }
        }
        
        return res;
    }
};

class Solution_3 {
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