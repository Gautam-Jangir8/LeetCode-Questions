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
    bool isCompleteTree(TreeNode* root) {
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            
            for(int i=0; i<n; i++) {
                TreeNode* front = q.front();
                q.pop();

                if(front->val==-1) {
                    ans.push_back(front->val);
                    continue;
                }
                ans.push_back(front->val);
                if(front->left) {
                    q.push(front->left);
                } else {
                    q.push(new TreeNode(-1));
                }
                if(front->right) {
                    q.push(front->right);
                } else {
                    q.push(new TreeNode(-1));
                }
            }
        }

        bool res = true;
        int j = ans.size()-1;
        while(ans[j]==-1) {
            j--;
        }
        while(j>0) {
            if(ans[j]==-1) {
                res = false;
                break;
            }
            j--;
        }

        return res;
    }
};