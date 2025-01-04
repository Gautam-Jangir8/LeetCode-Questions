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
class BSTIterator {
private:
    int ptr = -1;
    vector<int>inorder;

public:
    void inorderItr(TreeNode* root, vector<int>&inorder) {
        if(root==NULL) {
            return;
        }
        inorderItr(root->left, inorder);
        inorder.push_back(root->val);
        inorderItr(root->right, inorder);
    }

    BSTIterator(TreeNode* root) {
        inorderItr(root, inorder);
    }
    
    int next() {
        ptr++;
        return inorder[ptr];
    }
    
    bool hasNext() {
        if(ptr+1<inorder.size()) {
            return true;
        }
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */