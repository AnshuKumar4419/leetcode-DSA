class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            if (curr->val != val) {
                prev->next = curr;
                prev = curr;
            }
            curr = curr->next;
        }
        
        prev->next = nullptr;
        return dummy->next;
    }
};