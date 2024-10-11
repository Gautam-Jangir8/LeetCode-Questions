class Solution {
public:
    int help(vector<int>&stoneValue, int l, int r, int sum, vector<vector<int>>&dp) {
        if(l>=r) { // End of the recursion as only single element is left
            return 0; 
        }

        if(dp[l][r]!=-1) {
            return dp[l][r];
        }

        int ans = INT_MIN;
        int tot = 0;
        for(int i=l; i<=r; i++) {
            tot+=stoneValue[i];

            int rem = sum-tot;
            if(tot > rem) {
                ans = max(ans, rem + help(stoneValue, i+1, r, rem, dp));
            } else if(rem > tot){
                ans = max(ans, tot + help(stoneValue, l, i, tot, dp));
            } else { // case where there is a draw between left and right 
                ans = max(ans, max(tot + help(stoneValue, l, i, tot, dp), rem + help(stoneValue, i+1, r, rem, dp)));
            }
        }

        return dp[l][r] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        int sum = 0;
        for(auto i: stoneValue) {
            sum+=i;
        }

        return help(stoneValue, 0, n-1, sum, dp);
    }
};