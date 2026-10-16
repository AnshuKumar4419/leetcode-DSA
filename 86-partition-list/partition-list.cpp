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
        ListNode* temp = head;
        ListNode* small = new ListNode(0);
        ListNode* smallHead = small;
        ListNode* big = new ListNode(0);
        ListNode* bigHead = big;
        while(temp != NULL) {
            if(temp->val < x) {
                small->next = temp;
                small = temp;
            }
            else if(temp->val >= x) {
                big->next = temp;
                big = temp;
            }
            temp = temp->next;
        }
        big->next = nullptr;
        small->next = bigHead->next;
        return smallHead->next;
    }
};