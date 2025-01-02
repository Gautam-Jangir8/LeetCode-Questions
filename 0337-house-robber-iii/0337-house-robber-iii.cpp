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
    pair<int, int> solve(TreeNode* root) {
        if(root==NULL) {
            return {0, 0};
        }

        // Calculate for left and right children
        auto left = solve(root->left);
        auto right = solve(root->right);

        // If you rob the current Node, we cannot rob its children
        int robCurrent = root->val + left.second + right.second;// second specify that we have to skip it

        // If you skip the current node
        int skipCurrent = max(left.first, left.second) + max(right.first, right.second);

        return {robCurrent, skipCurrent};
    }

    int rob(TreeNode* root) {
        auto result = solve(root);
        return max(result.first, result.second);
    }
};