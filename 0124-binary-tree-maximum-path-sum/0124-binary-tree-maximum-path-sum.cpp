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
    int inorder(TreeNode* root, int & final) {
        if(root==NULL) {
            return 0;
        }

        int left = inorder(root->left, final);
        int right = inorder(root->right, final);

        int ans = max(root->val, max(root->val+left, root->val+right));
        final = max(final, max(ans, root->val+left+right));
        
        return ans; 
    }

    int maxPathSum(TreeNode* root) {
        int final = INT_MIN;
        inorder(root, final);

        return final;
    }
};