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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) {
            return NULL;
        }
        if(root->val==key) {
            return helper(root);
        }

        TreeNode* dummy = root;
        while(root!=NULL) {
            if(root->val>key) { // key is present in the left side of the binary tree
                if(root->left!=NULL && root->left->val==key) {
                    root->left = helper(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else { // key is present in the right side of the binary tree
                if(root->right!=NULL && root->right->val==key) {
                    root->right = helper(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }

        return dummy;
    }

    TreeNode* helper(TreeNode* root) {
        if(root->left==NULL) { // If there is nothingo on the left of the node to be deleted
            return root->right;
        } 
        if(root->right==NULL) { // If there is nothing on the right of the node to be deleted
            return root->left;
        }

        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

    TreeNode* findLastRight(TreeNode* root) {
        if(root->right==NULL) {
            return root;
        }
        return findLastRight(root->right);
    }
};