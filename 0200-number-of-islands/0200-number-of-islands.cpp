class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size() || grid[row][col]=='0' || vis[row][col]==1) {
            return;
        }

        vis[row][col] = 1;
        dfs(row+1, col, grid, vis);
        dfs(row-1, col, grid, vis);
        dfs(row, col+1, grid, vis);
        dfs(row, col-1, grid, vis);
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>>vis(rows, vector<int>(cols, 0));

        for(int r=0; r<rows; r++) {
            for(int c=0; c<cols; c++) {
                if(!vis[r][c] && grid[r][c]=='1') {
                    ans++;

                    dfs(r, c, grid, vis);
                }
            }
        }

        return ans;
    }
};