class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int>mp;
        int sum = 0;
        mp[sum]++;

        for(int i=0; i<nums.size(); i++)
        {
            sum+=nums[i];

            int rem = sum%k;
            if(rem<0)// Handling if the remender comes to be negative
            {
                rem+=k;
            }

            if(mp.find(rem)!=mp.end())
            {
                ans+=mp[rem];
            }
            mp[rem]++;
        }

        return ans;
    }
};