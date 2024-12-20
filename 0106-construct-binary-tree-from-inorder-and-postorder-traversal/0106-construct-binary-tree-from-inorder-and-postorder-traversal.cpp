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
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int inorderStart, int inorderEnd, int postorderStart, int postorderEnd, unordered_map<int, int>&mp) {
        if(inorderStart>inorderEnd || postorderStart > postorderEnd) {
            return NULL;
        }

        int rootValue = postorder[postorderEnd];
        TreeNode* root = new TreeNode(rootValue);
        int inorderRootIndex = mp[rootValue];
        int leftSubtreeSize = inorderRootIndex - inorderStart;

        root->left = helper(inorder, postorder, inorderStart, inorderRootIndex-1, postorderStart, postorderStart+leftSubtreeSize-1, mp);
        root->right = helper(inorder, postorder, inorderRootIndex+1, inorderEnd, postorderStart+leftSubtreeSize, postorderEnd-1, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()) {
            return NULL;
        }

        unordered_map<int, int>mp;
        for(int i=0; i<inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return helper(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1, mp);
    }
};