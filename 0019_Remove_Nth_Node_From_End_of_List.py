# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        # 自己做的
        # if head.next == None:
        #     return head.next

        # temp, frontHead = ListNode(0), ListNode(0)
        # count1 = 0
        # temp.next = head
        # while(temp.next != None):
        #     count1 += 1
        #     temp.next = temp.next.next

        # if count1 == n:
        #     return head.next

        # temp.next = head
        # for _ in range(count1 - n - 1):
        #     temp.next = temp.next.next

        # temp.next.next = temp.next.next.next

        # return head

        """
        双指针，只需要单趟扫描
        """
        temp = ListNode(0)
        temp.next = head
        p1, p2 = temp, temp

        for _ in range(n + 1):
            p1 = p1.next

        while(p1):
            p1 = p1.next
            p2 = p2.next

        p2.next = p2.next.next

        return temp.next
