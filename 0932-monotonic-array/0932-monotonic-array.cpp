class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        vector<int>temp = nums;
        vector<int>temp2 = nums;
        sort(temp.begin(), temp.end());
        sort(temp2.begin(), temp2.end(), greater<int>());

        return nums==temp || nums==temp2;
    }
};