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

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next!=NULL && fast->next->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = reverse(slow->next);
        slow->next = NULL;
        ListNode* A = head;
        ListNode* B = prev;

        while(A!=NULL && B!=NULL) {
            ListNode* A_next = A->next;
            ListNode* B_next = B->next;

            A->next = B;
            B->next = A_next;
            A = A_next;
            B = B_next;
        }
    }
};