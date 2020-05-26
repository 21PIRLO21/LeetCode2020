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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;

        while (l1 != nullptr && l2 != nullptr) {
            ListNode **pp = (l1->val <= l2->val) ? &l1 : &l2;
            cur->next = *pp;
            cur = cur->next;
            *pp = (*pp)->next;
        }
        cur->next = (l1 != nullptr) ? l1 : l2;

        ListNode * ans = dummy->next;
        delete dummy;

        return ans;
    }
};


class Solution_2 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } 
            else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = (l1 != nullptr) ? l1 : l2;

        ListNode * ans = dummy->next;
        delete dummy;

        return ans;
    }
};