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
void preorder(TreeNode *root, queue<TreeNode *> &q, int val)
{
    if (!root)
    {
        return;
    }

    if (root->val == val)
    {
        q.push(root);
    }

    preorder(root->left, q, val);
    preorder(root->right, q, val);
}

bool isSame(TreeNode *first, TreeNode *second)
{
    if (first == NULL && second == NULL)
    {
        return true;
    }
    if (first == NULL || second == NULL)
    {
        return false;
    }

    if (first->val != second->val)
    {
        return false;
    }

    return isSame(first->left, second->left) && isSame(first->right, second->right);
}

bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
    if (subRoot == NULL)
    {
        return true;
    }

    int val = subRoot->val;
    queue<TreeNode *> q;
    TreeNode *temp = root;
    preorder(temp, q, val); // Store all the occurance of root element of subRoot tree in queue and then match both the tree are same or not

    while (!q.empty())
    {
        TreeNode *first = q.front();
        q.pop();
        TreeNode *second = subRoot;

        if (isSame(first, second))
        {
            return true;
        }
    }

    return false;
}
};