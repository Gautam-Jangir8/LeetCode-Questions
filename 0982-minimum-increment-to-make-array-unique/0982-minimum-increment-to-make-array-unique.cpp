class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) 
    {
        int ans = 0;
        int count[200001] = {0};
        int mini = INT_MAX;

        for(int i=0; i<nums.size(); i++)
        {
            count[nums[i]]++;
            mini = min(mini, nums[i]);
        }

        int cnt = 0;
        int extra = 0;
        for(int i=mini; cnt<nums.size(); i++)
        {
            int f = count[i];
            cnt+=(f!=0);

            if(f<=1)
            {
                continue;
            }
            count[i+1]+=(f-1);
            ans+=f-1;
        }

        return ans;
    }
};