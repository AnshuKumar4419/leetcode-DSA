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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        stack<int> st;
        vector<int> ans;
        while(prev != NULL) {
            while(st.size() > 0 && prev->val >= st.top()) {
                st.pop();
            }
            if(st.empty()) {
                ans.push_back(0);
            }
            else {
                ans.push_back(st.top());
            }
            st.push(prev->val);
            prev = prev->next;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};