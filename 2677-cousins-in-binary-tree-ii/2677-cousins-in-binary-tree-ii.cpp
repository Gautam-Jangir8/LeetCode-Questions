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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root==NULL) {
            return NULL;
        }

        queue<TreeNode*>q;
        q.push(root);
        int prev = root->val;

        while(!q.empty()) {
            int n = q.size();
            int curr = 0;

            for(int i=0; i<n; i++) {
                TreeNode* front = q.front();
                q.pop();

                int leftRight = (front->left ? front->left->val : 0) + (front->right ? front->right->val : 0);

                if (front->left) {
                    front->left->val = leftRight;
                    q.push(front->left);
                }

                if (front->right) {
                    front->right->val = leftRight;
                    q.push(front->right);
                }

                curr += leftRight;
                front->val = prev - front->val;
            }
            prev = curr;
        }

        return root;
    }
};