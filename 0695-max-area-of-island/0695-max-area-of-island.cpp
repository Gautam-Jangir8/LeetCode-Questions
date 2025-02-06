class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> vis(rows, vector<int>(cols, 0));

        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                int temp = 0;
                if (!vis[r][c] && grid[r][c] == 1)
                {
                    int dx[4] = {1, 0, -1, 0};
                    int dy[4] = {0, 1, 0, -1};
                    queue<pair<int, int>> q;
                    q.push({r, c});
                    vis[r][c] = 1;

                    while (!q.empty())
                    {
                        pair<int, int> p = q.front();
                        int x = p.first;
                        int y = p.second;
                        q.pop();
                        temp++;

                        for (int i = 0; i < 4; i++)
                        {
                            int newX = x + dx[i];
                            int newY = y + dy[i];

                            if (newX >= 0 && newY >= 0 && newX < rows && newY < cols && grid[newX][newY] == 1 && !vis[newX][newY])
                            {
                                vis[newX][newY] = 1;
                                q.push({newX, newY});
                            }
                        }
                    }
                }

                ans = max(temp, ans);
            }
        }

        return ans;
    }
};