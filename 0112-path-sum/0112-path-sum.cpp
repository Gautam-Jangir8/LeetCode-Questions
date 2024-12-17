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
    void preorder(TreeNode* root, int targetSum, int sum, bool &temp) {
        if(root==NULL) {
            return;
        }
        
        if(root->left==NULL && root->right==NULL) {
            if(sum+root->val==targetSum) {
                temp = true;
            }    

            return;
        }

        preorder(root->left, targetSum, sum+root->val, temp); 
        preorder(root->right, targetSum, sum+root->val, temp); 
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        bool temp = false;
        if(root==NULL) {
            return temp;
        }

        preorder(root, targetSum, 0, temp);

        return temp;
    }
};