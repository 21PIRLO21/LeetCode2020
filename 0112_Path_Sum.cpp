#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

/* Easy */
/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// using double stack
class Solution_1 {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        
        stack<TreeNode *> stackNode;
        stack<int> stackSum; 
        stackNode.push(root);
        stackSum.push(root->val);
        TreeNode *ptr;
        int pathSum = 0;
        while (!stackNode.empty()) {
            ptr = stackNode.top();
            pathSum = stackSum.top();
            stackNode.pop();
            stackSum.pop();
            if (!ptr->left && !ptr->right) {
                if (pathSum == sum) return true;
                continue;
            }
            if (ptr->left != nullptr) {
                stackNode.push(ptr->left);
                stackSum.push(pathSum + ptr->left->val);
            }
            if (ptr->right != nullptr) {
                stackNode.push(ptr->right);
                stackSum.push(pathSum + ptr->right->val);
            }
        }
        return false;
    }
};

// the fastest
class Solution_2 {
public:
    bool hasPathSum(TreeNode* root, int sum) {
			if (!root)
				return false;
			if (root->val == sum && !root->left && !root->right)
				return true;
			return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
		}
};