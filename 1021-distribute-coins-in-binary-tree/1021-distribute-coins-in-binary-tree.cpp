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
    int postorder(TreeNode* root, int &cnt) {
        if(root==NULL) {
            return 0; // Zero denotes no requirement
        }

        int l = postorder(root->left, cnt);
        int r = postorder(root->right, cnt);
        cnt+=abs(l)+abs(r);

        return (root->val + l + r - 1);
    }

    int distributeCoins(TreeNode* root) {
        int cnt = 0;
        postorder(root, cnt);

        return cnt;
    }
};