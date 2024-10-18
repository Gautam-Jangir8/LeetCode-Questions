class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>set;
        for(int i=0; i<nums1.size(); i++) {
            set.insert(nums1[i]);
        }

        unordered_set<int>set2;
        for(int i=0; i<nums2.size(); i++) {
            if(set.find(nums2[i])!=set.end()) {
                set2.insert(nums2[i]);
            }
        }

        vector<int>vec(set2.begin(), set2.end());
        return vec;
    }
};