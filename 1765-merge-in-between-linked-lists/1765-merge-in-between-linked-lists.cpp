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
    ListNode* find(ListNode* list1, int a) {
        int cnt = 1;
        while(list1!=NULL) {
            if(cnt==a) {
                return list1;
            }
            cnt++;
            list1 = list1->next;
        }

        return NULL;
    }

    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* findA = find(list1, a);
        ListNode* findB = find(list1, b+2);

        ListNode* temp = list2;
        while(temp->next!=NULL) {
            temp = temp->next;
        }

        findA->next = list2; 
        temp->next = findB;

        return list1;
    }
};