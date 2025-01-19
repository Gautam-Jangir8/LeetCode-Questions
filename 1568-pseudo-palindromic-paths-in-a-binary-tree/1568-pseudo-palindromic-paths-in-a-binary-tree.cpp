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
    int pseudoPalindromicPaths (TreeNode* root) {
        int cnt = 0;
        stack<pair<TreeNode*, int>>stk;
        stk.push({root, 0});

        while(!stk.empty()) {
            pair<TreeNode*, int>p = stk.top();
            stk.pop();
            TreeNode* node = p.first;
            int path = p.second;

            if(node!=NULL) {
                path = path^(1<<node->val);
                if(node->left==NULL && node->right==NULL) { // Its a leaf node
                    if((path & (path-1))==0) {
                        cnt++;
                    }
                } else {
                    stk.push({node->right, path});
                    stk.push({node->left, path});
                }
            }
        }   

        return cnt;
    }
};