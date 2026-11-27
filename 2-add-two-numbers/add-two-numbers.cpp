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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* dummy1 = new ListNode(0);
        ListNode* dummy = dummy1;

        while(temp1 != NULL && temp2 != NULL) {
            int val = temp1->val + temp2->val;
            val = val + carry;
            if(val < 10) carry = 0;
            if(val > 9) {
                carry = 1;
                val = val % 10;
            }
            ListNode* Node = new ListNode(val);
            dummy->next = Node;
            dummy = dummy->next;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while(temp1 != NULL) {
            int val = temp1->val;
            val = val + carry;
            if(val < 10) carry = 0;
            if(val > 9) {
                carry = 1;
                val = val % 10;
            }
            ListNode* Node = new ListNode(val);
            dummy->next = Node;
            dummy = dummy->next;

            temp1 = temp1->next;
        }
        while(temp2 != NULL) {
            int val = temp2->val;
            val = val + carry;
            if(val < 10) carry = 0;
            if(val > 9) {
                carry = 1;
                val = val % 10;
            }
            ListNode* Node = new ListNode(val);
            dummy->next = Node;
            dummy = dummy->next;

            temp2 = temp2->next;
        }
        if(carry == 1) {
            ListNode* Node = new ListNode(1);
            dummy->next = Node;
            dummy = dummy->next;
        }
        return dummy1->next;
    }
};