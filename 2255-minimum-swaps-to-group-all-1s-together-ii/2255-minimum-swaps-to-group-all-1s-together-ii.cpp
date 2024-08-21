class Solution {
public:
    int minSwaps(vector<int>& nums) {
        // Counting the number of Ones, to decide the window size in array
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                cnt++;
            }
        }
        
        // To handle the circular array we will append the vector to the end 
        nums.insert(nums.end(), nums.begin(), nums.end());

        // Counting the number of zeros, that will be the number of swaps required
        int ans = cnt;
        int zeroCnt = 0;
        for (int i = 0; i < cnt; i++)
        {
            if (nums[i] == 0)
            {
                zeroCnt++;
            }
        }
        ans = min(zeroCnt, ans);

        for (int i = cnt; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                zeroCnt++;
            }
            if (nums[i - cnt] == 0)
            {
                zeroCnt--;
            }
            ans = min(zeroCnt, ans);
        }

        return ans;
    }
};