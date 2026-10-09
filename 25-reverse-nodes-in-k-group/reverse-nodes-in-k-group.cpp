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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next || k == 1) {
            return head;
        }

        ListNode dummy(0, head);
        ListNode* groupPrev = &dummy;

        ListNode* scout = head;
        int groupCount = 0;

        while (scout) {
            scout = scout->next;
            groupCount++;

            if (groupCount == k) {
                ListNode* groupTail = groupPrev->next;

                for (int i = 0; i < k - 1; i++) {
                    ListNode* nodeToMove = groupTail->next;
                    groupTail->next = nodeToMove->next;
                    nodeToMove->next = groupPrev->next;
                    groupPrev->next = nodeToMove;
                }

                groupPrev = groupTail;
                groupCount = 0;
            }
        }

        return dummy.next;
    }
};