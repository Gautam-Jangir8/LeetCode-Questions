class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long totSum = 0;
        for(auto i: nums) {
            totSum+=i;
        }

        int ans = 0;
        long currSum = 0;
        for(int i=0; i<nums.size()-1; i++) {
            currSum+=nums[i];
            totSum-=nums[i];

            if(currSum>=totSum) {
                ans++;
            }
        }
        return ans;
    }
};