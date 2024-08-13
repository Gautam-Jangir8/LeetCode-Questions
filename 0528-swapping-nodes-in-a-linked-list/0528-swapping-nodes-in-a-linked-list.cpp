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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
       
        int i = 0;
        while(i<k-1) {
            temp = temp->next;
            i++;
        }
        ListNode* ptr1 = temp;

        ListNode* temp2 = new ListNode(0);
        temp2->next = head;

        while(temp!=NULL) {
            temp = temp->next;
            temp2 = temp2->next;
        }
        ListNode* ptr2 = temp2;
        int data1 = ptr1->val;
        ptr1->val = ptr2->val; 
        ptr2->val = data1;

        return head;
    }
};