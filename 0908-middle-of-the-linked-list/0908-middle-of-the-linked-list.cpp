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
    ListNode* middleNode(ListNode* head) {
        if(head==NULL || head->next==NULL) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->next;
    }
};