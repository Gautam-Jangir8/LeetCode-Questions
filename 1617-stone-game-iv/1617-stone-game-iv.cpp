class Solution {
public:
    int help(int n, vector<int>&dp) {
        if(n<=0) { // Means we are going to loose the game
            return 0;
        }

        if(dp[n]!=-1) {
            return dp[n];
        }

        for(int i=1; i*i<=n; i++) {
            if(help(n-i*i, dp)==0) { // Passing the next person with 0 means we will win
                return dp[n] = 1;
            }
        }
        return dp[n] = 0;    
    }

    bool winnerSquareGame(int n) {
        vector<int>dp(n+1, -1);
        return help(n, dp);
    }
};