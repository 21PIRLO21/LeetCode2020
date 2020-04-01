#include <ostream>
#include <vector>
#include <algorithm>

using namespace std;

/* medium */
/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 需要断链表
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // if(!head)
        //     return NULL;
        // if(!(head -> next))
        //     return new TreeNode(head -> val);
        if(head == NULL)
            return NULL;
        if(head -> next == NULL)
            return new TreeNode(head -> val);
        // 构造一个链表头结点，使得链表非头结点的操作具有一致性
        ListNode *headNode = new ListNode(0); 
        headNode -> next = head;
        
        ListNode *slow = headNode, *fast = headNode;
        ListNode *slow_pre = NULL; // 用来切断链表，始终指向slow之前的一个结点
        while(fast != NULL && fast -> next != NULL){
            slow_pre = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        TreeNode *root = new TreeNode(slow -> val);
        slow_pre -> next = NULL;
        root -> left = sortedListToBST(headNode -> next);
        root -> right = sortedListToBST(slow -> next);
        
        return root;
    }
};

// 不需要断链表
/*class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return buildTree(head, nullptr);
    }
    TreeNode * buildTree(ListNode* head, ListNode * tail){
        if(head == tail) return nullptr;
        ListNode* slow = head, *fast = head;
        while(fast != tail && fast->next != tail){
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode * root = new TreeNode(slow->val);
        root->left = buildTree(head, slow);
        root->right = buildTree(slow->next, tail);
        return root;
    }
};*/