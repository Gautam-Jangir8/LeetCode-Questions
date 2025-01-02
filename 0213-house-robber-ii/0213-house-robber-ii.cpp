class Solution {
public:
    int solve(int idx, vector<int> &nums, vector<int> &dp)
    {
        if (idx < 0)
        {
            return 0;
        }

        if (dp[idx] != -1)
        {
            return dp[idx];
        }

        // NotTake
        int notTake = solve(idx - 1, nums, dp);
        // Take
        int take = nums[idx] + solve(idx - 2, nums, dp);

        return dp[idx] = max(take, notTake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) {
            return nums[0];
        }

        vector<int> dp1(n, -1), dp2(n, -1);
        int first = solve(n - 2, nums, dp1);
        reverse(nums.begin(), nums.end());
        int second = solve(n - 2, nums, dp2);

        return max(first, second);
    }
};