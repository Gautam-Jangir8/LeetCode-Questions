class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& memo) {
        int n = grid.size();
        int m = grid[0].size();

        // If this cell is already computed, return the memoized result
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        int maxMoves = 0;

        // Check possible moves to (i-1, j+1), (i, j+1), (i+1, j+1)
        for (int d = -1; d <= 1; d++) {
            int newRow = i + d;
            int newCol = j + 1;

            if (newRow >= 0 && newRow < n && newCol < m && grid[newRow][newCol] > grid[i][j]) {
                maxMoves = max(maxMoves, 1 + dfs(newRow, newCol, grid, memo));
            }
        }

        // Memoize the result before returning
        memo[i][j] = maxMoves;
        return maxMoves;
    }

    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxAns = 0;

        // Memoization table initialized to -1 (unvisited)
        vector<vector<int>> memo(n, vector<int>(m, -1));

        // Start DFS from each cell in the first column
        for (int i = 0; i < n; i++) {
            maxAns = max(maxAns, dfs(i, 0, grid, memo));
        }

        return maxAns;
    }
};