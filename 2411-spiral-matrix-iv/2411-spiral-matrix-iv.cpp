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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
         vector<vector<int>> matrix(m, vector<int>(n, 0));

        int r1 = 0, c1 = 0, r2 = m - 1, c2 = n - 1;
        
        while (r1 <= r2 && c1 <= c2)
        {
            for (int i = c1; i <= c2; i++)
            {
                if(head!=NULL) {
                    matrix[r1][i] = head->val;
                    head = head->next;
                } else {
                    matrix[r1][i] = -1;
                }
            } 
            r1++;
            if(r1>r2 || c1>c2) {
                break;
            }

            for (int i = r1; i <= r2; i++)
            {
                if(head!=NULL) {
                    matrix[i][c2] = head->val;
                    head = head->next;
                } else {
                    matrix[i][c2] = -1;
                }
            }
            c2--;
            if(r1>r2 || c1>c2) {
                break;
            }

            for (int i = c2; i >= c1; i--)
            {
                if(head!=NULL) {
                    matrix[r2][i] = head->val;
                    head = head->next;
                } else {
                    matrix[r2][i] = -1;
                }
            }
            r2--;
            if(r1>r2 || c1>c2) {
                break;
            }
            
            for (int i = r2; i >= r1; i--)
            {
                if(head!=NULL) {
                    matrix[i][c1] = head->val;
                    head = head->next;
                } else {
                    matrix[i][c1] = -1;
                }
            }
            c1++;
            if(r1>r2 || c1>c2) {
                break;
            }
        }

        return matrix;
    }
};