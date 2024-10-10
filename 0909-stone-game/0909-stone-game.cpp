class Solution {
public:
    int AliceWin(bool turn, int l, int r, vector<int>&piles, vector<vector<int>>&dp) {
        if(l>r) {
            return 0; // Now no one can pick, recursion over 
        }
        if(l==r) {
            return piles[l]; // Last step to consider
        }

        if(dp[l][r]!=-1) {
            return dp[l][r];
        }

        int total = 0;
        if(turn) { // If turn is true, means it's alice turn
            total += max(piles[l] + AliceWin(!turn, l+1, r, piles, dp), piles[r] + AliceWin(!turn, l, r-1, piles, dp));
        } else { // Bob's turn
            total += min(-piles[l] + AliceWin(!turn, l+1, r, piles, dp), -piles[r] + AliceWin(!turn, l, r-1, piles, dp));
        }

        return dp[l][r] = total;
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(505, vector<int>(505, -1));

        // If End score is greater then 0 then Alice wins, return true, else return false
        return AliceWin(1, 0, n-1, piles, dp) > 0; // Here initial 1 indicates that it is the turn of alice first
    }
};