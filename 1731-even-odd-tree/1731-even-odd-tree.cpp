/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if(!root) {
            return true; // Empty tree is valid
        }

        queue<TreeNode*>q;
        q.push(root);
        int level = 0;

        while(!q.empty()) {
            int n = q.size();

            int prev = (level%2==0) ? INT_MIN : INT_MAX; // This will help in check increasing and decreasing sequence
            
            for(int i=0; i<n; i++) {
                TreeNode* front = q.front();
                q.pop();
                int val = front->val;

                // Check value parity and order constraints
                if(level%2==0) {
                    // Even indexed level: odd values, strictly increasing
                    if(val%2==0 || val<=prev) {
                        return false;
                    }
                } else {
                    // Odd indexed level: even value, strictly decreasing
                    if(val%2!=0 || val>=prev) {
                        return false;
                    }
                }

                prev = val; // Update the value of previous with the current value

                if(front->left) {
                    q.push(front->left);
                }
                if(front->right) {
                    q.push(front->right);
                }
            }

            level++;
        }

        return true;
    }
};