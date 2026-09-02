/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp = headA;
        int n1 = 0;
        while(temp != NULL) {
            n1++;
            temp = temp->next;
        }

        temp = headB;
        int n2 = 0;
        while(temp != NULL) {
            n2++;
            temp = temp->next;
        }

        int d = abs(n1 - n2);

        if(n1 > n2) {
            while(d > 0) {
                headA = headA->next;
                d--;
            }
        }
        else {
            while(d > 0) {
                headB = headB->next;
                d--;
            }
        }
        while(headB != NULL) {
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};