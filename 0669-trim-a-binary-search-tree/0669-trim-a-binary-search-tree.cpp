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
    TreeNode* inorder(TreeNode* root, int low, int high) {
        if(root==NULL) {
            return NULL;
        }

        root->left = inorder(root->left, low, high);
        root->right = inorder(root->right, low, high);

        if(root->val<low || root->val>high) {
            if(root->left==NULL) {
                return root->right;
            } else {
                return root->left;
            }
        }

        return root; 
    }

    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return inorder(root, low, high);
    }
};