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
    int maxLevelSum(TreeNode* root) 
    {
        queue<TreeNode*>q;
        q.push(root);

        int eleSum = root->val;
        int currLevel = 1;
        int maxLevel = 1;
        while(!q.empty()) {
            int n = q.size();
            
            long long sum = 0;
            for(int i=0; i<n; i++) {
                TreeNode* front = q.front();
                q.pop();
                sum+=front->val;

                if(front->left) {
                    q.push(front->left);
                } 
                if(front->right) {
                    q.push(front->right);
                }
            }

            if(sum>eleSum) {
                eleSum = sum;
                maxLevel = currLevel;
            }

            currLevel++;
        }

        return maxLevel;
    }
};