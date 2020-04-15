#include <ostream>
#include <vector>
#include <algorithm>

using namespace std;

/* easy */

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution_1 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *newHead = NULL;
        ListNode *next = NULL;
        // 原 head 充当一个临时前驱指针
        while (head) {
            next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }
        return newHead;
    }
};

class Solution_1_ {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* p1 = head;
        ListNode* cur = NULL;
        while (p1) {
            // 自己定义 临时前驱指针
            ListNode* t = p1->next;
            p1->next = cur;
            cur = p1;
            p1 = t;
        }
        return cur;
    }
};

class Solution_2 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *cur, *pre;
        cur = nullptr;
        pre = head;
        while (pre != nullptr) {
            ListNode *t_ptr = cur;
            cur = pre;
            pre = pre->next;
            cur->next = t_ptr;
        }
        return cur;
    }
};