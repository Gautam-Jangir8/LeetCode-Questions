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
    vector<TreeNode*> allPossibleFBT(int n) {
        // For even number of nodes there cannot be any possible solution
        if(n%2==0) {
            return {};
        }
        if(n==1) {
            return {new TreeNode(0)};
        }

        vector<TreeNode*>ans;
        for(int i=1; i<n; i++) {
            vector<TreeNode*>left = allPossibleFBT(i);
            vector<TreeNode*>right = allPossibleFBT(n-i-1);

            for(TreeNode* l: left) {
                for(TreeNode* r: right) {
                    ans.push_back(new TreeNode(0, l, r));
                }
            }
        }

        return ans;
    }
};