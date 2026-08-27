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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL) {
            cnt++;
            temp = temp->next;
        }
        if(n == cnt) {
            ListNode* curr = head;
            head = head->next;
            delete curr;
            return head;
        }
        int k = cnt - n + 1;
        cnt = 0;
        temp = head;
        while(temp != NULL) {
            cnt++;
            if(cnt == k - 1) {
                ListNode* curr = temp->next;
                temp->next = temp->next->next;
                delete curr;
                return head;
            }
            temp = temp->next;
        }
        return head;
    }
};