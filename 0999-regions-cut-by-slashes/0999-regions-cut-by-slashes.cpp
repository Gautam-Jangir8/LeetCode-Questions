class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>>matrix(3*n, vector<int>(3*n, 0));

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                int row = i*3;
                int col = j*3;

                if(grid[i][j]=='/') {
                    matrix[row][col+2] = 1;
                    matrix[row+1][col+1] = 1;
                    matrix[row+2][col] = 1;
                } else if (grid[i][j]=='\\'){
                    matrix[row][col] = 1;
                    matrix[row+1][col+1] = 1;
                    matrix[row+2][col+2] = 1;
                } 
                // Else will be if it is an empty string
            }
        }

        int dirX[4] = {0, 1, 0, -1};
        int dirY[4] = {1, 0, -1, 0};
        int count = 0;
        vector<vector<int>>vis(3*n, vector<int>(3*n, 0));
        for(int i=0; i<3*n; i++) {
            for(int j=0; j<3*n; j++) {
                if(matrix[i][j]==0 && vis[i][j]==0) {
                    vis[i][j] = 1;
                    count++;

                    queue<pair<int, int>>q;
                    q.push({i, j});

                    while(!q.empty()) {
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();

                        for(int i=0; i<4; i++) {
                            int nRow = row+dirX[i];
                            int nCol = col+dirY[i];

                            if(nRow>=0 && nCol>=0 && nRow<3*n && nCol<3*n && 
                                matrix[nRow][nCol]==0 && vis[nRow][nCol]==0) {
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
};