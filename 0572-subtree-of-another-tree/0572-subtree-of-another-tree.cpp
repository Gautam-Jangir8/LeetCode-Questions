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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
        {
            return true;
        }
        if (p == NULL || q == NULL)
        {
            return false;
        }

        if (p->val != q->val)
        {
            return false;
        }

        if (isSameTree(p->left, q->left) == false)
        {
            return false;
        }
        if (isSameTree(p->right, q->right) == false)
        {
            return false;
        }

        return true;
    }

    void inorder(TreeNode* root, TreeNode* subRoot, bool & temp) {
        if(root==NULL) {
            return;
        }

        if(isSameTree(root, subRoot)) {
            temp = true;
        }
        inorder(root->left, subRoot, temp);
        inorder(root->right, subRoot, temp);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool temp = false;
        inorder(root, subRoot, temp);

        return temp;
    }
};