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
    TreeNode* build(vector<int>nums, int start, int end) {
        if(start>end) {
            return NULL;
        }        

        int mid = (start+end)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build(nums, start, mid-1);
        root->right = build(nums, mid+1, end);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // If there is no element in the vector so return NULL
        if(nums.size()==0) {
            return NULL;
        }

        // Put the middle element as the root element
        return build(nums, 0, nums.size()-1);     
    }
};