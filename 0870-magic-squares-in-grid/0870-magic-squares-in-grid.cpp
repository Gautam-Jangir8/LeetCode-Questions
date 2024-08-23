class Solution {
public:
    bool isValid(int i, int j, vector<vector<int>>&grid) {
        // To check if the count of any number is greater then 1 then it cannot be our one of the answer
        vector<int>count(10, 0);
        for(int x=0; x<3; x++) {
            for(int y=0; y<3; y++) {
                int num = grid[i+x][j+y];
                if(num<1 || num>9 || count[num]>0) {
                    return false;
                }
                count[num]++;
            }
        }

        // Sum of row 1st for comparison
        int sum = grid[i][j]+grid[i][j+1]+grid[i][j+2];
        // Checking for all the rows
        for(int x=0; x<3; x++) {
            if(sum != (grid[i+x][j]+grid[i+x][j+1]+grid[i+x][j+2])) {
                return false;
            }
        }
        // Chekcing for all the Columns
        for(int y=0; y<3; y++) {
            if(sum != (grid[i][j+y]+grid[i+1][j+y]+grid[i+2][j+y])) {
                return false;
            }
        }

        // Now checking for both the digonals
        if(sum != (grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2])) {
            return false;
        }
        if(sum != (grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j])) {
            return false;
        }

        // If all the conditions of false not executed, means we got our one answer
        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();

        // Base case
        if(n<3 || m<3) {
            return 0;
        }

        for(int i=0; i<=n-3; i++) {
            for(int j=0; j<=m-3; j++) {
                if(isValid(i, j, grid)) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};