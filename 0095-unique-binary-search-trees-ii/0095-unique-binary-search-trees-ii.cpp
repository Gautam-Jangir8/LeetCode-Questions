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
    vector<TreeNode*> generateTreesDistinct(int start, int end) {
        if(start>end) {
            return {NULL};
        }
        if(start==end) {
            return {new TreeNode(start)};
        }

        vector<TreeNode*>res;
        // Har node ko root banana ki kosis karanga
        for(int i=start; i<=end; i++) {
            vector<TreeNode*>left = generateTreesDistinct(start, i-1);
            vector<TreeNode*>right = generateTreesDistinct(i+1, end);

            for(auto l: left) {
                for(auto r: right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;

                    res.push_back(root);
                }
            }

        }

        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        return generateTreesDistinct(1, n);
    }
};