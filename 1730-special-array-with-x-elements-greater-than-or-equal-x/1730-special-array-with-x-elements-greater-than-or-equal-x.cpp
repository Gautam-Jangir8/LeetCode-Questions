class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();

        // Applying Binary Search on this array
        int start = 0, end = n;
        while(start<=end) {
            int mid = (start+end)/2;
            
            int count = 0;
            for(int i=0; i<n; i++) {
                if(nums[i]>=mid) {
                    count++;
                }
            }

            if(mid==count) {
                return mid;
            } else if(mid<count) {
                start = mid+1;
            } else {
                end = mid-1;
            }
        }

        return -1;
    }
};