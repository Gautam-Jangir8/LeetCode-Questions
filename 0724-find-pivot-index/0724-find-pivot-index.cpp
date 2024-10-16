class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++) {
            sum+=nums[i];
        }

        int tempSum = 0;
        for(int i=0; i<nums.size(); i++) {
            if(tempSum==(sum-tempSum-nums[i])) {
                return i;
            }
            tempSum+=nums[i];
        }

        return -1;
    }   
};