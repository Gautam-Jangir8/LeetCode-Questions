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
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nex;

        while(curr!=NULL) {
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }

        return prev;
    }
    
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp1 = head;
        int i = 0;
        while(i<k-1) {
            temp1 = temp1->next;
            i++;
        }

        head = reverse(head);
        ListNode* temp2 = head;
        i = 0;
        while(i<k-1) {
            temp2 = temp2->next;
            i++;
        }

        int data1 = temp1->val;
        temp1->val = temp2->val;
        temp2->val = data1;

        return reverse(head);
    }
};