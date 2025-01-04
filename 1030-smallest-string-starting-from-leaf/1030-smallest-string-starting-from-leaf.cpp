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
    void inorder(TreeNode* root, string temp, string &ans) {
        if(root==NULL) {
            return;
        }
        if(root->left==NULL && root->right==NULL) {
            temp+=(root->val+'a');
            string str = temp;
            reverse(str.begin(), str.end());
            
            if(ans=="" || str<ans) {
                ans = str;
            } 
            return;
        }

        temp.push_back(root->val+'a');
        inorder(root->left, temp, ans);
        inorder(root->right, temp, ans);
    }

    string smallestFromLeaf(TreeNode* root) {
        string ans = "";
        inorder(root, "", ans);

        return ans;
    }
};