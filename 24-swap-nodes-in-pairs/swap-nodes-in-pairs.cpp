class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0, head);
        ListNode *prev = &dummy, *cur = head;

        while (cur && cur->next) {
            ListNode *next = cur->next->next;
            ListNode *second = cur->next;

            second->next = cur;
            cur->next = next;
            prev->next = second;

            prev = cur;
            cur = next;
        }

        return dummy.next;        
    }
};