class Solution {
public:
    int help(vector<int>&piles, int i, int M, vector<vector<int>>&dp) {
        if(i>=piles.size()) {
            return 0;
        }

        if(dp[i][M]!=-1) {
            return dp[i][M];
        }

        int total = 0;
        int ans = INT_MIN;
        for(int j=0; j<2*M; j++) {
            if(i+j<piles.size()) {
                total+=piles[i+j];
            }
            ans = max(ans, total - help(piles, i+j+1, max(M, j+1), dp));
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        vector<vector<int>>dp(101, vector<int>(202, -1));// {i, M}, M can be maximum double of i
        int sum = 0;
        for(auto i: piles) {
            sum+=i;
        }
        
        int diff = help(piles, 0, 1, dp);// {piles, index, M}
        // If the diff is negative means bob will have more stones and he will win, else Alice will win.
        // (Total + diff)/2 i.e x-y = diff, x+y = sum => x = (sum+diff)/2
        
        return (sum+diff)/2;
    }
};