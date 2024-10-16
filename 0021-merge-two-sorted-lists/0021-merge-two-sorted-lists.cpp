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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode(-1);
        ListNode* dummy = ans;

        while(list1!=NULL && list2!=NULL) {
            if(list1->val < list2->val) {
                dummy->next = new ListNode(list1->val);
                list1 = list1->next;
            } else {
                dummy->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            dummy = dummy->next;
        }

        if(list1!=NULL) {
            dummy->next = list1;
        } else {
            dummy->next = list2;
        }

        return ans->next;
    }
};