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

    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);

        ListNode* temp = head;
        ListNode* nex = temp->next;
        int maxi = head->val;

        while(nex!=NULL) {
            if(nex->val<maxi) {
                temp->next = nex->next;
                nex = temp->next;
            } else {
                maxi = max(maxi, nex->val);
                temp = temp->next;
                nex = nex->next;
            }
        }

        return reverse(head);
    }
};