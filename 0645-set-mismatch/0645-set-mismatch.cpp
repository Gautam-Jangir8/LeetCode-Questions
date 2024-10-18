class Solution {
public:
    // Without using extra space
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        for(int i=0; i<nums.size(); i++) {
            int temp = abs(nums[i]);
            sum+=temp;
            if(nums[temp-1]>0) {
               nums[temp-1] *= -1;
            }
        }

        int nonRepeated = -1;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]>0) {
                nonRepeated = i+1;
                break;
            }
        }
        int diff = (n*(n+1)/2)-sum;

        return {nonRepeated-diff, nonRepeated};
    }
};