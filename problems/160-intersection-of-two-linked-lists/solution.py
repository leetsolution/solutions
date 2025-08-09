# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        if not headA or not headB:
            return None

        a_pointer = headA
        b_pointer = headB

        while a_pointer != b_pointer:
            a_pointer = headB if a_pointer is None else a_pointer.next
            b_pointer = headA if b_pointer is None else b_pointer.next

        return a_pointer