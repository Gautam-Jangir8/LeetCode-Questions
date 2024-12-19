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
    string seralizeTree(TreeNode* root, vector<TreeNode*>&ans, unordered_map<string, int>&mp) {
        if(root==NULL) {
            return "";
        }
        string left = seralizeTree(root->left, ans, mp);
        string right = seralizeTree(root->right, ans, mp);
        int rootValue = root->val;
        string formed = to_string(rootValue)+"$"+left+"$"+right;
        if(mp[formed]==1) { // If the count of formed is 1 then only push the root to the answer
            ans.push_back(root);
        }
        mp[formed]++;

        return formed;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>ans;
        unordered_map<string, int>mp;
        seralizeTree(root, ans, mp);

        return ans;
    }
};