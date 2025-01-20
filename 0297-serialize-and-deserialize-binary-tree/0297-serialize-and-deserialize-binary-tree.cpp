/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // Using Level Order Traversal for the Serialization
        if(root==NULL) {
            return "";
        }

        string str = "";
        queue<TreeNode*>q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            if (front) {
                str += to_string(front->val) + ","; // Add delimiter
                q.push(front->left);
                q.push(front->right);
            } else {
                str += "#,"; // Represent null with '#'
            }
        }

        return str;
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") {
            return NULL;
        }

        stringstream ss(data);
        string val;
        getline(ss, val, ','); // Get the root value
        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            // Process left child
            if (getline(ss, val, ',')) {
                if (val == "#") {
                    front->left = NULL;
                } else {
                    front->left = new TreeNode(stoi(val));
                    q.push(front->left);
                }
            }

            // Process right child
            if (getline(ss, val, ',')) {
                if (val == "#") {
                    front->right = NULL;
                } else {
                    front->right = new TreeNode(stoi(val));
                    q.push(front->right);
                }
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));