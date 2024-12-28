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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd, int preStart, int preEnd, unordered_map<int, int>&mp) {
        if(inStart>inEnd || preStart>preEnd) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[preStart]); 
        int idx = mp[preorder[preStart]];
        int sizeleft = idx-inStart;
        root->left = solve(preorder, inorder, inStart, idx-1, preStart+1, preStart+sizeleft, mp);
        root->right = solve(preorder, inorder, idx+1, inEnd, preStart+sizeleft+1, preEnd, mp);

        return root; 
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int>mp;
        for(int i=0; i<inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return solve(preorder, inorder, 0, inorder.size()-1, 0, preorder.size()-1, mp);
    }
};