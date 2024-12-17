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
    int check(TreeNode* root, bool &temp) {
        if(root==NULL) {
            return 0;
        }
        if(root->left==NULL && root->right==NULL) {
            return 1;
        }

        int left = check(root->left, temp);
        int right = check(root->right, temp);

        if(abs(left-right)>1) {
            temp = false;
        }

        return max(left, right)+1;
    }

    bool isBalanced(TreeNode* root) {
        bool temp = true;
        check(root, temp);

        return temp;
    }
};