class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        if(n==0) {
            return {};
        }

        int i=0, j=n-1;

        while(i<=j) {
            if(nums[i]==val) {
                swap(nums[i], nums[j]);
                j--;
            } else {
                i++;
            }
        }

        return i;
    }
};