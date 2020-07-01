#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

/* Hard */
/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 与 LeetCode 297 类似
class Solution_1 {
private:
    int cur = 0; // 全局变量cur去处理节点值(遍历string)
    int cur_D = 0;
public:
    TreeNode* DFS(int depth, string &nodes){
        int val = 0;
        // for ( ; cur <  nodes.size() && nodes[cur] != '-'; cur++) {
        //     val = val * 10 + nodes[cur] - '0';
        // }
        while (cur <  nodes.size() && nodes[cur] != '-') {
            val = val * 10 + nodes[cur] - '0';
            cur++;
        }
        
        cur_D = 0; // 全局变量cur_D维护当前遍历到的深度
        // for ( ; cur < nodes.size() && nodes[cur] == '-'; cur++, cur_D++) {};
        while (cur < nodes.size() && nodes[cur] == '-') {
            cur++;
            cur_D++;
        }
        
        // 如果cur_D > depth则显然全局遍历的下一节点为当前节点的子节点，递归到下一层深度
        // 否则为其长辈节点（叔父节点，祖叔父节点...），跳过递归
        TreeNode *r = new TreeNode(val);
        if (cur_D > depth) r->left = DFS(cur_D, nodes);
        if (cur_D > depth) r->right = DFS(cur_D, nodes);
        
        return r;
    }
    TreeNode* recoverFromPreorder(string S) {
        // string nodes = S;
        // return DFS(0, nodes);
        return DFS(0, S);
    }
};

// the fastest
class Solution_2 {
public:
    TreeNode* recoverFromPreorder(string S) {
        int len = S.size();
        if(len == 0) return NULL;

        stack<TreeNode*> stackNode;
        stack<int> stackDepth;
        int p = 0;
        int tempNum = 0;
        int tempDepth = 0;
        bool bNum = false;
        TreeNode* root = NULL;
        while(p <= len){
            if(p == len || S[p] == '-'){
                if(bNum){   // 解析了一个数字
                    TreeNode* node = new TreeNode(tempNum);
                    if(stackNode.size() == 0){  // 根节点
                        root = node;
                    }else{  // 其他节点
                        while(stackDepth.top() >= tempDepth){   // 找到首个父节点
                            stackDepth.pop();
                            stackNode.pop();
                        }
                        TreeNode* parent = stackNode.top();
                        if(!parent->left) 
                            parent->left = node;
                        else
                            parent->right = node;
                    }

                    stackNode.push(node);
                    stackDepth.push(tempDepth);
                    tempNum = 0;
                    tempDepth = 0;
                    bNum = false;
                }
                tempDepth++;
            }else{
                tempNum = tempNum*10 + (int)(S[p]-'0');
                bNum = true;
            }
            p++;
        }

        return root;
    }
};