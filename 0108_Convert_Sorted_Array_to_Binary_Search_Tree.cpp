#include <ostream>
#include <vector>
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

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) { 
//         int n = nums.size();
//         if(!n)
//             return NULL;
        
//         int mid = n / 2;
//         TreeNode *pt = new TreeNode(nums[mid]);
//         vector<int> leftNums, rightNums;
        
//         for(int i = 0; i < mid; ++i)
//             leftNums.push_back(nums[i]);
//         for(int j = mid + 1; j < n; ++j)
//             rightNums.push_back(nums[j]);
        
//         pt -> left = sortedArrayToBST(leftNums);
//         pt -> right = sortedArrayToBST(rightNums);
        
//         return pt;
        int n = nums.size();
        int begin = 0, end = n - 1;
        return helper(nums, begin, end);
    }
    
    TreeNode * helper(vector<int>& nums, int begin, int end){
        if(begin > end)
            return NULL;
        int mid = (begin + end) / 2;
        TreeNode * pt = new TreeNode(nums[mid]);
        pt->left = helper(nums, begin, mid - 1);
        pt->right = helper(nums, mid + 1, end);
        return pt;
    }
};