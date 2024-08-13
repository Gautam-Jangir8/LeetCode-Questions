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
    // Function to revesre the Linked List
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* nex;
        ListNode* prev = NULL;

        while(curr!=NULL) {
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }

        return prev;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head = reverse(head);
        ListNode* temp = head;

        while(n>1) {
            temp = temp->next;
            n--;
        }

        if(temp->next==NULL) {
            head = reverse(head);
            return head->next;
        }
        temp->val = temp->next->val;
        temp->next = temp->next->next;
        head = reverse(head);

        return head;
    }
};