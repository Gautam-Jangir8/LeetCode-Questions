class Solution {
public:
    int numberOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dirX[4] = {1, 0, -1, 0};
        int dirY[4] = {0, 1, 0, -1};
        int count = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Condition for New Island
                if (grid[i][j] == 1 && vis[i][j] == 0) {

                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vis[i][j] = 1;
                    count++;

                    while (!q.empty()) {
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();

                        for (int i = 0; i < 4; i++) {
                            int nRow = row + dirX[i];
                            int nCol = col + dirY[i];

                            if (nRow >= 0 && nCol >= 0 && nRow < n &&
                                nCol < m && grid[nRow][nCol] == 1 &&
                                vis[nRow][nCol] == 0) {
                                q.push({nRow, nCol});
                                vis[nRow][nCol] = 1;
                            }
                        }
                    }
                }
            }
        }

        return count;
    }

    int minDays(vector<vector<int>>& grid) { 
        int n = grid.size();
        int m = grid[0].size();

        // If the number of island is 0 and greater then 1 then it is already seperated, do return 0
        if(numberOfIsland(grid)==0 || numberOfIsland(grid)>1) {
            return 0;
        }    

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]==1) {
                    grid[i][j] = 0;

                    if(numberOfIsland(grid)==0 || numberOfIsland(grid)>1) {
                        return 1;
                    }
                    grid[i][j] = 1;
                }
            }
        }

        return 2;
    }
};