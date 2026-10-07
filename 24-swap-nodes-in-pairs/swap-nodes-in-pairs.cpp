class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0, head);
        ListNode *prev = &dummy;
        ListNode *cur = head;

        while (cur != NULL && cur->next != NULL) {
            ListNode *second = cur->next->next;
            ListNode *first = cur->next;

            first->next = cur;
            cur->next = second;
            prev->next = first;

            prev = cur;
            cur = second;
        }

        return dummy.next;        
    }
};