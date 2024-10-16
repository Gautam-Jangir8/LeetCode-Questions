class NumArray {
public:
    vector<int>ans;
    NumArray(vector<int>& nums) {
        for(int i: nums) {
            ans.push_back(i);
        }
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        for(int i=left; i<=right; i++) {
            sum+=ans[i];
        }

        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */