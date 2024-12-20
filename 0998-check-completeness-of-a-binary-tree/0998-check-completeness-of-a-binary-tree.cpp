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
        queue<TreeNode *> q;
        q.push(root);
        bool encounteredNULL = false;

        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();

            if (front == NULL)
            { // Mark that we have encountered a NULL node, if we find a not null node after this, then the tree is not complete
                encounteredNULL = true;
            }
            else
            {
                // If we have already encountered a NULL node, the tree is not complete
                if (encounteredNULL == true)
                {
                    return false;
                }
                // Add left and right children to the queue
                q.push(front->left);
                q.push(front->right);
            }
        }

        return true;
    }
};