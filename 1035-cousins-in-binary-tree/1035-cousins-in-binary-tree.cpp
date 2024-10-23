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
    bool isCousins(TreeNode* root, int x, int y) {
        unordered_map<int, TreeNode*>mp;// Child to Parent Mapping
        queue<TreeNode*>q;
        q.push(root);
        mp[root->val] = new TreeNode(-1);

        while(!q.empty()) {
            int n = q.size();
            
            bool first = false, second = false;
            for(int i=0; i<n; i++) {
                TreeNode* front = q.front();
                q.pop();

                if(front->val==x) {
                    first = true;
                }
                if(front->val==y) {
                    second = true;
                }

                if(front->left) {
                    mp[front->left->val] = front;
                    q.push(front->left);
                } 
                if(front->right) {
                    mp[front->right->val] = front;
                    q.push(front->right);
                }

                if(first==true && second==true) {
                    if(mp[x]!=mp[y]) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};