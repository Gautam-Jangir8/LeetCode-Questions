class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n, vector<int>(n, -1));

        int r1 = 0, c1 = 0, r2 = n - 1, c2 = n - 1;
        int cnt = 1;
        while (r1 <= r2 && c1 <= c2)
        {
            for (int i = c1; i <= c2; i++)
            {
                matrix[r1][i] = cnt;
                cnt++;
            }
            r1++;
            for (int i = r1; i <= r2; i++)
            {
                matrix[i][c2] = cnt;
                cnt++;
            }
            c2--;

            if (r1 > r2 || c1 > c2)
            {
                break;
            }

            for (int i = c2; i >= c1; i--)
            {
                matrix[r2][i] = cnt;
                cnt++;
            }
            r2--;
            for (int i = r2; i >= r1; i--)
            {
                matrix[i][c1] = cnt;
                cnt++;
            }
            c1++;
        }

        return matrix;
    }
};