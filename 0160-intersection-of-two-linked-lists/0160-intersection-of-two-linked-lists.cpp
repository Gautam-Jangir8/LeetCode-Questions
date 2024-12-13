/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* dummyA = headA;
        ListNode* dummyB = headB;

        while(dummyA != dummyB) {
            if(dummyA==NULL) {
                dummyA = headB;
            } else {
                dummyA = dummyA->next;
            }
            if(dummyB==NULL) {
                dummyB = headA;
            }
            else {
                dummyB = dummyB->next;
            }
        }

        return dummyA;
    }
};