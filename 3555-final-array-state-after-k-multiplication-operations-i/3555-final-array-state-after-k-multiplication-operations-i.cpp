class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        
        while(k>0) {
            int minEle = INT_MAX;
            int minEleIdx = -1;
            for(int i=0; i<nums.size(); i++) {
                if(nums[i]<minEle) {
                    minEle = nums[i];
                    minEleIdx = i;
                }
            }
            nums[minEleIdx] = nums[minEleIdx] * multiplier;
            k--;
        }

        return nums;
    }
};