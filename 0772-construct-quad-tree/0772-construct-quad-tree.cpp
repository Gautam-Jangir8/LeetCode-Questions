/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return helper(grid, 0, 0, grid.size());
    }

    Node* helper(vector<vector<int>>&grid, int i, int j, int w) {
        if(allSame(grid, i, j, w)) { // If all the elements in the grid is same, then the grid is theleaf node
            return new Node(grid[i][j], true); // Here true indicates that it is a leaf node
        }

        // Process the node if it is not leaf node
        Node* node = new Node(1, false); // Here false indicate that the node is not the leaf node
        node->topLeft = helper(grid, i, j, w/2);
        node->topRight = helper(grid, i, j+w/2, w/2);
        node->bottomLeft = helper(grid, i+w/2, j, w/2);
        node->bottomRight = helper(grid, i+w/2, j+w/2, w/2);

        return node;
    }

    bool allSame(vector<vector<int>>&grid, int i, int j, int w) {
        for(int x=i; x<i+w; x++) {
            for(int y=j; y<j+w; y++) {
                if(grid[x][y] != grid[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};