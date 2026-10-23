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
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int, int> mp;
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        ListNode* temp = head;
        while(temp != NULL) {
            mp[temp->val]++;
            temp = temp->next;
        }
        temp = head;
        while(temp != NULL) {
            if(mp[temp->val] == 1) {
                curr->next = temp;
                curr = curr->next;
            }
            temp = temp->next;
        }
        curr->next = NULL;
        return dummy->next;
    }
};