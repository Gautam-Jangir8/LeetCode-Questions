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
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = head;
        dummy->next = head;
        int curr = INT_MAX;

        while(temp!=NULL) {
            if(temp->val!=curr) {
                curr = temp->val;
                temp = temp->next;
                dummy = dummy->next;
            } else {
                dummy->next = temp->next;
                temp = dummy->next;
            }
        }

        return head;
    }
};