class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int>cnt(101, 0);

        int ans = 0;
        for(int i=0; i<nums.size(); i++) {
            ans+=cnt[nums[i]];
            cnt[nums[i]]++;
        }

        return ans;
    }
};