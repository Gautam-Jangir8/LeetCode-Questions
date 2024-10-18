class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long totalSum = 0;
        for(auto i: nums) {
            totalSum += i;
        }

        // Find the reminder when totalSum is divided by p
        int rem = totalSum%p;
        if(rem==0) {
            return 0; // If the reminder is 0, no subarray needs to be removed
        }

        unordered_map<int, int>mp;
        mp[0] = -1; // initialize for handling full prefix
        long preSum = 0;
        int minLength = nums.size();

        for(int i=0; i<nums.size(); i++) {
            preSum+=nums[i];
            int currMod = preSum%p;
            int tarMod = (currMod -rem + p) % p;

            if(mp.find(tarMod)!=mp.end()) {
                minLength = min(minLength, i-mp[tarMod]);
            }
            mp[currMod] = i;
        }

        return minLength==nums.size() ? -1 : minLength;
    }
};