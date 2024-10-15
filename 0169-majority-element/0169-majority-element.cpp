class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>mp;
        for(auto i: nums) {
            mp[i]++;
        }

        int count = 0;
        for(auto i: mp) {
            if(i.second>(n/2)) {
                return i.first;
            }
        }

        return -1;
    }
};