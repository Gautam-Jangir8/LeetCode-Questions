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
    bool dfs(TreeNode* root, long long l, long long r) {
        if(root==NULL) {
            return true;
        }

        if(root->val<r && root->val>l) {
            return dfs(root->left, l, root->val) && dfs(root->right, root->val, r);
        }
        else {
            return false;
        }
    }

    bool isValidBST(TreeNode* root) {
        long long int min = -1000000000000, max = 1000000000000;
        return dfs(root, min, max);
    }
};