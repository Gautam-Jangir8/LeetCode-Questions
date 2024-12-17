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
    void inorder(TreeNode* root, vector<int>&ans) {
        if(root==NULL) {
            return;
        }
        if(root->left==NULL && root->right == NULL) {
            ans.push_back(root->val);
        }
        inorder(root->left, ans);
        inorder(root->right, ans);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>col1, col2;

        inorder(root1, col1);
        inorder(root2, col2);

        return col1==col2;
    }
};