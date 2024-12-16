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
    // Here we will do level order traversal
    int maxDepth(TreeNode* root) {
        int depth = 0;
        queue<TreeNode*>q;
        q.push(root);

        if(root==NULL) {
            return 0;
        }

        while(!q.empty()) {
            int n = q.size();
            depth++;

            for(int i=0; i<n; i++) {
                TreeNode* front = q.front();
                q.pop();

                if(front->left) {
                    q.push(front->left);
                }
                if(front->right) {
                    q.push(front->right);
                }
            }
        }

        return depth;
    }
};