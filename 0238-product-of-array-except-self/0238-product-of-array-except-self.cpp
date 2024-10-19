class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>preProd(n, 0), postProd(n, 0);

        preProd[0] = nums[0];
        for(int i=1; i<n; i++) {
            preProd[i] = preProd[i-1]*nums[i];
        }
        postProd[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--) {
            postProd[i] = postProd[i+1]*nums[i];
        }

        for(int i=0; i<n; i++) {
            if(i==0) {
                nums[i] = postProd[i+1];
            } else if(i==n-1) {
                nums[i] = preProd[i-1];
            } else {
                nums[i] = preProd[i-1] * postProd[i+1];
            }
        }

        return nums;
    }
};