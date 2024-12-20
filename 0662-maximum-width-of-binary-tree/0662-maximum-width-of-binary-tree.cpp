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
    int widthOfBinaryTree(TreeNode* root) {
        long long ans = 1;
        queue<pair<TreeNode*, long long>>q;
        q.push({root, 0});

        while(!q.empty()) {
            long long n = q.size();
            long long start = q.front().second;
            long long end = q.back().second;

            ans = max(ans, end-start+1);

            for(int i=0; i<n; i++) {
                pair<TreeNode*, long long>p = q.front();
                q.pop();
                long long idx = p.second - start;

                if(p.first->left) {
                    q.push({p.first->left, 2*idx+1});
                }
                if(p.first->right) {
                    q.push({p.first->right, 2*idx+2});
                }
            } 
        }
        
        return ans;
    }
};