class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        mp[0] = -1;
        int sum = 0;

        for(int i=0; i<nums.size(); i++)
        {
            sum+=nums[i];

            int temp = k==0 ? sum : sum % k;
            if(mp.find(temp)!=mp.end())
            {
                if(i-mp[temp]>=2)
                {
                    return true;
                }
            }
            else
            {
                mp[temp] = i;
            }
        }

        return false;
    }
};

// int n = nums.size();
//         unordered_map<int, int> remainderMap;
//         int cumulativeSum = 0;
        
//         // Step 1: Initialize Remainder Map
//         remainderMap[0] = -1;
        
//         // Step 2: Iterate Through the List
//         for (int i = 0; i < n; i++) {
//             // Step 3: Calculate Cumulative Sum
//             cumulativeSum += nums[i];
            
//             // Step 4: Calculate Remainder
//             int remainder = k == 0 ? cumulativeSum : cumulativeSum % k;
            
//             // Step 5: Update Remainder Map
//             if (remainderMap.count(remainder)) {
//                 // Check if segment length is at least two
//                 if (i - remainderMap[remainder] > 1) {
//                     return true;
//                 }
//             } else {
//                 remainderMap[remainder] = i;
//             }
//         }
        
//         // Step 6: Return the Result