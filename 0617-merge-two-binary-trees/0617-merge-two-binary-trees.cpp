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
    TreeNode* mergeBoth(TreeNode* root1, TreeNode* root2) {
        // If both the nodes are present
        if(root1 && root2) {
            root1->val += root2->val;
            root1->left = mergeBoth(root1->left, root2->left);
            root1->right = mergeBoth(root1->right, root2->right);
        } else { // if one node dosen't exist, then link it back to the calling node
            return root1 ? root1 : root2; // If root1 not NULL then return root1 else return root2
        }

        return root1;// return the first tree, which is altered. No need to create a new Node which can bloat the memory
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL) {
            return root2;
        }
        if(root2==NULL) {
            return root1;
        }

        return mergeBoth(root1, root2);
    }
};