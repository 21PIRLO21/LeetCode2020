#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

/* Easy */
/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution_1 {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        unordered_set<int> occurred = {head->val};
        ListNode* pos = head;
        // 枚举前驱节点
        while (pos->next != nullptr) {
            // 当前待删除节点
            ListNode* cur = pos->next;
            if (!occurred.count(cur->val)) { // set.count()
                occurred.insert(cur->val);
                pos = pos->next;
            } else {
                pos->next = pos->next->next;
            }
        }
        pos->next = nullptr;
        return head;
    }
};

// the fastest
class Solution_2 {
private:
bool vis[20001] = {0};
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* cur = head;
        ListNode* pre = head;
        vis[cur->val] = true;
        cur = cur->next;

        while(cur!=NULL)
        {
            if(vis[cur->val])
            {
                pre->next = cur->next;
                cur = pre->next;
            }
            else
            {
                vis[cur->val] = true;
                pre = cur;
                cur = cur->next;
            }
        }

        return head;
    }
};