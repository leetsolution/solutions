/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *pA = headA;
    struct ListNode *pB = headB;

    while (pA != pB) {
        if (pA == NULL) {
            pA = headB;
        } else {
            pA = pA->next;
        }

        if (pB == NULL) {
            pB = headA;
        } else {
            pB = pB->next;
        }
    }

    return pA;
}