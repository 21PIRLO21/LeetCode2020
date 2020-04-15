#include <ostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

/* medium */

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 用vector做栈
class Solution_1 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> stack1, stack2;
        for (ListNode *p1 = l1; p1 != nullptr; ) {
            stack1.push_back(p1->val);
            p1 = p1->next;
        }
        for (ListNode *p2 = l2; p2 != nullptr; ) {
            stack2.push_back(p2->val);
            p2 = p2->next;
        }
        
        int cur = 0;
        ListNode *res = nullptr;
        while (!stack1.empty() || !stack2.empty() || cur != 0) {
            // ListNode *new_node = new ListNode(0);
            auto new_node = new ListNode(0);
            new_node->next = res;
            res = new_node;
            // int a = stack1.empty() ? 0 : stack1.pop_back();
            // int b = stack2.empty() ? 0 : stack2.pop_back();
            int a = stack1.empty() ? 0 : stack1.back();
            int b = stack2.empty() ? 0 : stack2.back();
            if (!stack1.empty()) {
                stack1.pop_back();
            }
            if (!stack2.empty()) {
                stack2.pop_back();
            }
            cur = a + b + cur;
            new_node->val = cur % 10;
            cur /= 10;
        }
        return res;
    }
};

// 用stack做栈
class Solution_2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1 -> val);
            l1 = l1 -> next;
        }
        while (l2) {
            s2.push(l2 -> val);
            l2 = l2 -> next;
        }
        int carry = 0;
        ListNode* ans = nullptr;
        while (!s1.empty() || !s2.empty() || carry != 0) {
            int a = s1.empty() ? 0 : s1.top();
            int b = s2.empty() ? 0 : s2.top();
            if (!s1.empty()) s1.pop();
            if (!s2.empty()) s2.pop();
            int cur = a + b + carry;
            carry = cur / 10;
            cur %= 10;
            auto curnode = new ListNode(cur);
            curnode -> next = ans;
            ans = curnode;
        }
        return ans;
    }
};

// 最快
class Solution_3 {
public:
    ListNode *reverse(ListNode *head){
        ListNode *pre=NULL,*cur=head,*temp;
        while (cur) {
            temp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=temp;
        }
        return pre;
    }
    ListNode* addTwo(ListNode* l1, ListNode* l2) {
	    ListNode preHead(0), *p = &preHead;
        int extra = 0;
        while (l1 || l2 || extra) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
            extra = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return preHead.next;
	}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        l1 = addTwo(l1,l2);
        return reverse(l1);
    }
};