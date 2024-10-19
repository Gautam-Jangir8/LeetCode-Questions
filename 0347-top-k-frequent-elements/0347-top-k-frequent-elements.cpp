class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;

        // Frequency of the elements are stored;
        for(auto i: nums) {
            mp[i]++;
        }

        vector<pair<int, int>>vec;
        for(auto i: mp) {
            vec.push_back({i.second, i.first});
        }
        sort(vec.begin(), vec.end(), greater<>());

        vector<int>ans;
        int i=0;
        while(i<k) {
            ans.push_back(vec[i].second);
            i++;
        }

        return ans;
    }
};