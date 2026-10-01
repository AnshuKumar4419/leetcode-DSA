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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        int size = 0;
        while(temp != NULL) {
            size++;
            temp = temp->next;
        }
        temp = head;
        int first = k - 1;
        int second = size - k;
        int swap1 = 0;
        int swap2 = 0;
        for(int i = 0; i < size; i++) {
            if(i == first) {
                swap1 = temp->val;
            }
            if(i == second) {
                swap2 = temp->val;
            }
            temp = temp->next;
        }
        temp = head;
        for(int i = 0; i < size; i++) {
            if(i == first) {
                temp->val = swap2;
            }
            if(i == second) {
                temp->val = swap1;
            }
            temp = temp->next;
        }
        return head;
    }
};