#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/* hard */
/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution_1 {
public:
    ListNode* mergeTwoLists(ListNode *a, ListNode *b) {
        if ((!a) || (!b)) return a ? a : b;
        ListNode head(-1), *tail = &head, *aPtr = a, *bPtr = b;
        while (aPtr && bPtr) {
            if (aPtr->val < bPtr->val) {
                tail->next = aPtr; aPtr = aPtr->next;
            } else {
                tail->next = bPtr; bPtr = bPtr->next;
            }
            tail = tail->next;
        }
        tail->next = (aPtr ? aPtr : bPtr);
        return head.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *ans = nullptr;
        for (size_t i = 0; i < lists.size(); ++i) {
            ans = mergeTwoLists(ans, lists[i]);
        }
        return ans;
    }
};

class Solution_2 {
public:
    // 方法1，队列，时间复杂度O(NlogK)
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        // 特殊输入
        if (lists.empty()) return nullptr;
        if (lists.size() == 1) return lists[0];

        // 定义队列，将所有链表插入
        queue<ListNode*> qL;

        // 将所有链表插入队列
        for (int i = 0; i < lists.size(); i++)
            qL.push(lists[i]);
        
        // 每一次从队列中选择两个元素，将其合并，之后再插入队列中
        while (qL.size() >= 2)
        {
            ListNode* first = qL.front();
            qL.pop();
            ListNode* second = qL.front();
            qL.pop();
            ListNode* merge = mergeList(first, second);
            qL.push(merge);
        }
        return qL.front();
    }

    // ListNode* mergeList(ListNode* l1, ListNode* l2)
    // {
    //     // 特殊输入
    //     if (l1 == nullptr) return l2;
    //     if (l2 == nullptr) return l1;

    //     // 定义双指针指向两个链表，定义result的伪头结点
    //     ListNode *p1 = l1, *p2 = l2;
    //     ListNode *first = new ListNode(-1);
    //     ListNode *pres = first;

    //     // 遍历两个链表
    //     while (p1 != nullptr || p2 != nullptr)
    //     {
    //         if (p1 == nullptr)
    //         {
    //             pres->next = p2;
    //             break;
    //         }
    //         if (p2 == nullptr)
    //         {
    //             pres->next = p1;
    //             break;
    //         }

    //         if (p1->val < p2->val)
    //         {
    //             pres->next = p1;
    //             p1 = p1->next;
    //         }
    //         else
    //         {
    //             pres->next = p2;
    //             p2 = p2->next;
    //         }
    //         pres = pres->next;
    //     }
    //     return first->next;
    // }

    ListNode* mergeList(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        p->next = l1 ? l1 : l2;
        return head->next;
    }

    // // 方法2，优先级队列，时间复杂度为O(NlogK)
    // ListNode* mergeKLists(vector<ListNode*>& lists)
    // {
    //     // 特殊输入
    //     if (lists.empty()) return nullptr;
    //     if (lists.size() == 1) return lists[0];

    //     // 定义优先级队列，保存K个链表的首元素值
    //     priority_queue<int> pq;


    // }
};