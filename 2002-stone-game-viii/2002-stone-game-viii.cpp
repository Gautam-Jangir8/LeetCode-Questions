class Solution {
public:
    int help(vector<int>&prefixSum, int i, vector<int>&dp) {
        int n = prefixSum.size();

        if(i==n-1) {
            return prefixSum[i];
        }

        // If the result of DP[i] is already calculated, return it
        if(dp[i]!=-1) {
            return dp[i];
        }

        int ans = max(help(prefixSum, i+1, dp), prefixSum[i]-help(prefixSum, i+1, dp));

        return dp[i] = ans;
    }

    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        // Prefix sum to calculate the cummulative sums
        vector<int>prefixSum(n, 0);
        prefixSum[0] = stones[0];

        // Create prefix sums array
        for(int i=1; i<n; i++) {
            prefixSum[i] = prefixSum[i-1] + stones[i];
        }

        // Initialize dp array for memoization with -1 (indicating uncalculated subproblems)
        vector<int> dp(n, -1);
        return help(prefixSum, 1, dp);

    }
};