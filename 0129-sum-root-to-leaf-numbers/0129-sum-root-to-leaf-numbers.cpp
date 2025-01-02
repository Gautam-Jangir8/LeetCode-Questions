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
    void preorder(TreeNode* root, int temp, int &sum) {
        if(root==NULL) {
            return;
        }
        // Case when we have found leaf node
        if(root->left==NULL && root->right==NULL) {
            sum+=(temp*10+root->val);
            return;
        }


        preorder(root->left, temp*10+root->val, sum);
        preorder(root->right, temp*10+root->val, sum);
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0;
        preorder(root, 0, sum);

        return sum;
    }
};