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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        ListNode* temp = head;
        ListNode* evenHead = new ListNode(0);
        ListNode* even = evenHead;

        while(temp != NULL && temp->next != NULL) {
            prev->next = temp;
            even->next = temp->next;
            temp = temp->next->next;
            prev = prev->next;
            even = even->next;
        }
        if(temp != NULL) {
            prev->next = temp;
            prev = prev->next;
        }
        even->next = NULL;
        prev->next = evenHead->next;
        return dummy->next;
    }
};