class Solution {
public:
    int help(vector<int>&s, int i, vector<int>&dp) { // Here i uis senoting the starting point of the vector
        if(i>=s.size()) {
            return 0;
        }

        if(dp[i]!=-1) {
            return dp[i];
        }

        int ans = INT_MIN;
        ans = max(ans, s[i]-help(s, i+1, dp));
        if(i+1<s.size()) {
            ans = max(ans, s[i]+s[i+1]-help(s, i+2, dp));
        }
        if(i+2<s.size()) {
            ans = max(ans, s[i]+s[i+1]+s[i+2]-help(s, i+3, dp));
        }

        return dp[i] = ans;
    }

    string stoneGameIII(vector<int>& s) {
        // Gives minimum difference between Alice score and bob score, as we are biased towards alice, we want alice to win
        vector<int>dp(s.size(), -1);
        
        int alice = help(s, 0, dp);
        if(alice>0) {
            return "Alice";
        } else if(alice==0) {
            return "Tie";
        } return "Bob";
    }
};