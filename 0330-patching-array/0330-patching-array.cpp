class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long maxNumber = 0;
        int i=0, minNumberPatch = 0, sz = nums.size();

        while(maxNumber < n) {
            if(i<sz && maxNumber+1 >= nums[i]) {
                maxNumber += nums[i];
                i++;
            } else {
                minNumberPatch++;
                maxNumber += (maxNumber+1);
            }
        }

        return minNumberPatch;
    }
};