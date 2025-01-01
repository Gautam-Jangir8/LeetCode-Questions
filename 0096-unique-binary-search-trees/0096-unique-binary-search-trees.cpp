class Solution {
public:
    int numTrees(int n) {
        vector<int>dp(n+1, 0);
        dp[0] = 1; // One way to construct empty tree
        dp[1] = 1; // One way to construct a tree with one node

        for(int i=2; i<=n; i++) {
            int temp = 0;
            for(int j=0; j<i; j++) {
                temp+=dp[j]*dp[i-j-1];
            }
            dp[i] = temp;
        }

        return dp[n];
    }
};