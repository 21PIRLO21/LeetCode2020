#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Medium */
/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution_1 {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return root;
        }
        
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        }
        else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        else {
            if (root->left == NULL) {
                return root->right;
            }
            else if (root->right == NULL) {
                return root->left;
            }
            else {
                TreeNode *temp = root->right;
                while (temp->left) {
                    temp = temp->left;
                };
                temp->left = root->left;
                return root->right;
            }
        }
        
        return root; // 切记不要忘记这里的return
    }
};

// the fastest
class Solution_2 {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        }
        if (root->val == key) {
            TreeNode *left = root->left;
            TreeNode *right = root->right;
            if (left == nullptr) {
                return right;
            }
            if (right == nullptr) {
                return left;
            }
            TreeNode *p = right;
            for ( ; p->left != nullptr; p = p->left) {
            }
            p->left = left;
            return right;
        } else if (root->val > key) { // 左子树
            root->left = deleteNode(root->left, key);
        } else {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};