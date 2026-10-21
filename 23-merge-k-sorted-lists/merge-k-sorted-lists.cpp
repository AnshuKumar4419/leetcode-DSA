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
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* tail = &dummy;
        
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        tail->next = l1 ? l1 : l2; // attach the leftover part
        return dummy.next;
    }

    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        if (lists.size() % 2 == 0) { // make length odd
            lists.push_back(nullptr);
        }
        
        int mid = lists.size() / 2;
        for (int i = 1; i <= mid; ++i) {
            lists[i] = merge2Lists(lists[i], lists[i - 1]); // left sweep →
        }
        for (int i = 1; i <= mid; ++i) {
            lists[lists.size() - i - 1] = merge2Lists(lists[lists.size() - i - 1], lists[lists.size() - i]); // right sweep ←
        }
        
        return lists[mid];
    }
};
