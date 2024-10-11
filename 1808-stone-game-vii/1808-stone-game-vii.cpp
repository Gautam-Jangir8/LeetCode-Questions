class Solution {
public:
    int help(vector<int>&stones, int l, int r, int turn, int sum, vector<vector<int>>&dp) {
        if(l>r) { // When both pointer cross each other, end of the recursion
            return 0;
        }

        if(dp[l][r]!=-1) {
            return dp[l][r];
        }


        // We are finding the maximum difference, as we want alice to win
        int ans=INT_MIN;
        // For alice turn
        if(turn==0) {
            ans = max((sum-stones[l])-help(stones, l+1, r, !turn, sum-stones[l], dp), (sum-stones[r])-help(stones, l, r-1, !turn, sum-stones[r], dp));
        } else {
            ans = max((sum-stones[l])-help(stones, l+1, r, !turn, sum-stones[l], dp), (sum-stones[r])-help(stones, l, r-1, !turn, sum-stones[r], dp));
        }

        return dp[l][r] = ans;
    }

    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        int sum = 0;
        for(auto i: stones) {
            sum+=i;
        }

        return help(stones, 0, n-1, 0, sum, dp); // last zero indicates that it is alice turn 
    }
};