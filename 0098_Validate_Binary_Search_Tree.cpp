#include <ostream>
#include <vector>

using namespace std;


/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    // 中序遍历非递归，LDR
    bool isValidBST(TreeNode* root) {
        if(root  == NULL)
            return true;
        TreeNode *nodeStack[5000], *temp = root;
        // nodeStack[0] = root;
        int top = -1;
        long min_val = LONG_MIN;
        while(top >= 0 || temp){
            while(temp){
                nodeStack[++top] = temp;
                temp = temp -> left;
            }
            temp = nodeStack[top--];
            if(temp -> val <= min_val)
                return false;
            min_val = temp -> val;
            temp = temp -> right;
        }
        return true;
    }
};

/* // 最快的答案
class Solution 
{
public:
    bool isValidBST(TreeNode* root) 
    {
        return dfs(root,INT_MIN,INT_MAX);
    }

    bool dfs(TreeNode* root,long long minv,long long maxv)
    {
        if(!root) return true;
        if(root->val < minv || root->val > maxv) return false;
        
        //[负无穷，x - 1]和[x + 1,正无穷]中寻找
        return dfs(root->left,minv,root->val - 1ll) && dfs(root->right,root->val + 1ll,maxv);
    }
};
*/