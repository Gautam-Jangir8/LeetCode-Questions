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

    int pairSum(ListNode* head) {
        if(head==NULL) {
            return 0;
        }

        vector<int>ans;

        ListNode* curr = head;
        while(curr!=NULL) {
            ans.push_back(curr->val);
            curr = curr->next;
        }

        int i = 0;
        head = reverse(head);
        while(head!=NULL) {
            ans[i] += head->val;
            head = head->next;
            i++;
        }

        int maxi = 0;
        for(int i=0; i<ans.size(); i++) {
            maxi = max(maxi, ans[i]);
        }

        return maxi;
    }
};