/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    while (head != NULL && head->val == val) {
        head = head->next;
    }
    if (head == NULL) {
        return NULL;
    }
    struct ListNode* current = head;
    while (current->next != NULL) {
        if (current->next->val == val) {
            current->next = current->next->next;
        } else {
            current = current->next;
        }
    }
    return head;
}