/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* curr = head;
        ListNode* prev = new ListNode(-1000);
        ListNode* temp = prev;
        while(curr != NULL) {
            if(curr->val == val) {
                curr = curr->next;
            }
            else {
                prev->next = curr;
                prev = curr;
                curr = curr->next;
            }
        }
        prev->next = NULL;
        return temp->next;
    }
};