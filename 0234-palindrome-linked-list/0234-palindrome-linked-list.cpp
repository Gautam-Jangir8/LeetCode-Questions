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
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nex;

        while(curr!=NULL) {
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        vector<int>before;
        while(temp!=NULL) {
            before.push_back(temp->val);
            temp = temp->next;
        }

        ListNode* newHead = reverse(head);
        vector<int>after;
        temp = newHead;
        while(temp!=NULL) {
            after.push_back(temp->val);
            temp = temp->next;
        }

        for(int i=0; i<after.size(); i++) {
            cout<<after[i]<<" ";
            cout<<before[i]<<" ";
            if(after[i]!=before[i]) {
                return false;
            }
        }

        return true;
    }
};