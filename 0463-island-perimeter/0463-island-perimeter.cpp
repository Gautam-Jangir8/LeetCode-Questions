class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(vis[i][j]==0 && grid[i][j]==1) {
                    queue<pair<int, int>>q;
                    q.push({i, j});
                    vis[i][j] = 1;

                    while(!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();

                        for(int k=0; k<4; k++) {
                            int newX = x + dx[k];
                            int newY = y + dy[k];

                            if(newX>=0 && newY>=0 && newX<n && newY<m && !vis[newX][newY] && grid[newX][newY]==1) {
                                q.push({newX, newY});
                                vis[newX][newY] = 1;
                            }
                            else if(newX<0 || newY<0 || newX>=n || newY>=m || grid[newX][newY]==0) {
                                ans++;
                            }
                        }
                    }
                }   
            }
        }

        return ans;
    }
};