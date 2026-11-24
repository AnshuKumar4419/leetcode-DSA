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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = new ListNode(0);
        ListNode* lessHead = less;
        ListNode* greater = new ListNode(0);
        ListNode* greaterHead = greater;
        ListNode* temp = head;
        while(temp != NULL) {
            if(temp->val < x) {
                less->next = temp;
                less = less->next;
            }
            else {
                greater->next = temp;
                greater = greater->next;
            }
            temp = temp->next;
        }
        greater->next = NULL;
        less->next = greaterHead->next;
        return lessHead->next;
    }
};