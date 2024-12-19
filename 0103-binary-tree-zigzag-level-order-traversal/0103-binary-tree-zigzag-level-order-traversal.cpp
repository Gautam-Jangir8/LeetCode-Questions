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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) {
            return ans;
        }

        queue<TreeNode*>q;
        q.push(root);
        int cnt = 0;

        while(!q.empty()) {
            vector<int>temp;
            int n = q.size();

            for(int i=0; i<n; i++) {
                TreeNode* front = q.front();
                q.pop();
                temp.push_back(front->val);

                if(front->left) {
                    q.push(front->left);
                }
                if(front->right) {
                    q.push(front->right);
                }
            }

            if(cnt%2!=0) {
                reverse(temp.begin(), temp.end());
            }
            ans.push_back(temp);
            cnt++;
        }

        return ans;
    }
};