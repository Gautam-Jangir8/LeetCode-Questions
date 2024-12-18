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
    void construct(TreeNode* root, string &str) {
        if(root==NULL) {
            return;
        }

        if(root->left) {
            str+='(';
            str+=to_string(root->left->val);
            construct(root->left, str);
            str+=')';
        } 
        if(root->right) {
            if(!root->left) {
                str+="()";
            }
            str+='(';
            str+=to_string(root->right->val);
            construct(root->right, str);
            str+=')';
        }
    }

    string tree2str(TreeNode* root) {
        string str = "";
        str+=to_string(root->val);
        construct(root, str);

        return str;
    }
};