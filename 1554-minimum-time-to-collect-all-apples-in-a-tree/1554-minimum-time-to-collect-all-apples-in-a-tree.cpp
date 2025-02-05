class Solution {
public:
    int dfs(int node, int myCost, vector<bool>hasApple, vector<int>adjList[], vector<int>&vis) {
        if(vis[node]) {
            return 0;
        }

        vis[node] = true;
        int childCost = 0;
        for(auto child: adjList[node]) {
            childCost += dfs(child, 2, hasApple, adjList, vis);// 2 because from parent to child node jana ka liya 2 cost to aayaga
        }

        if(childCost==0 && !hasApple[node]) {// It means there is no child 
            return 0;
        }

        return myCost + childCost;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int>adjList[n];
 
        // Making the Adjacency List
        for(auto i: edges) {
            adjList[i[0]].push_back(i[1]);
            adjList[i[1]].push_back(i[0]);
        }

        vector<int>vis(n, 0);
        return dfs(0, 0, hasApple, adjList, vis);
    }
};