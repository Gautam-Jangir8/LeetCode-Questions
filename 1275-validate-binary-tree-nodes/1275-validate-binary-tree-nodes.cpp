class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int>inDegree(n, 0); // To track the parent count of each node

        // Count indegree for each node
        for(int i=0; i<n; i++) {
            if(leftChild[i]!=-1) {
                inDegree[leftChild[i]]++;
                if(inDegree[leftChild[i]]>1) { // Node has more then one parent.
                    return false;
                }
            }
            if(rightChild[i]!=-1) {
                inDegree[rightChild[i]]++;
                if(inDegree[rightChild[i]]>1) { // Node has more then one parent.
                    return false;
                }
            }
        }

        // Finding the roor (Node with inDegree 0)
        int rootCount = 0;
        int root=-1;
        for(int i=0; i<n; i++) {
            if(inDegree[i]==0) {
                rootCount++;
                root = i;
            }
        }

        // There must be exectly one root
        if(rootCount!=1) {
            return false;
        }

        // Perform BFS to ensure all nodes are connected
        vector<bool>visited(n, false);
        queue<int>q;
        q.push(root);
        visited[root] = true;

        int visitedCount = 0;
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            visitedCount++;

            // Check the leftChild
            if(leftChild[front]!=-1) {
                if(visited[leftChild[front]]) { // If left child of the node is already visited, means cycle detacted
                    return false;
                }
                visited[leftChild[front]] = true;
                q.push(leftChild[front]);
            }
            // Check the rightChild
            if(rightChild[front]!=-1) {
                if(visited[rightChild[front]]) { // If left child of the node is already visited, means cycle detacted
                    return false;
                }
                visited[rightChild[front]] = true;
                q.push(rightChild[front]);
            }
        }

        return n==visitedCount;
    }
};