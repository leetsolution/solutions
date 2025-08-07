/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getDecimalValue(struct ListNode* head) {
    int decimalValue = 0;
    while (head != NULL) {
        decimalValue = (decimalValue << 1) | head->val;
        head = head->next;
    }
    return decimalValue;
}