class Solution {
public:
    void subsets(int idx, vector<int>&nums, int &cnt, vector<int>temp, int maxOr) {
        if(idx==nums.size()) { // Base Condition
            int tempOr = 0;
            for(int i=0; i<temp.size(); i++) {
                tempOr = tempOr | temp[i];
            }

            if(tempOr==maxOr) {
                cnt++;
            }
            return;
        }

        // Not Take
        subsets(idx+1, nums, cnt, temp, maxOr);

        // Take
        temp.push_back(nums[idx]);
        subsets(idx+1, nums, cnt, temp, maxOr);
        temp.pop_back();
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(int i=0; i<nums.size(); i++) {
            maxOr = maxOr | nums[i];
        }

        int cnt = 0;
        vector<int>temp;
        subsets(0, nums, cnt, temp, maxOr);

        return cnt;
    }
};