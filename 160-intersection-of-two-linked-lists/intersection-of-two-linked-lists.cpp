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
        ListNode *a = headA;
        unordered_map<ListNode*, int> mp;
        
        while (a != NULL) {
            mp[a]++;
            a = a->next;
        }
        a = headB;
        while(a != NULL) {
            if(mp[a] > 0) {
                return a;
            }
            a = a->next;
        }
        
        return NULL;
    }
};