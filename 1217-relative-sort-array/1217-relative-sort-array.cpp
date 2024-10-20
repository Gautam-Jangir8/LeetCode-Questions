class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int>mp;

        for(int i=0; i<arr1.size(); i++)
        {
            mp[arr1[i]]++;
        }

        vector<int>ans;
        for(int i=0; i<arr2.size(); i++)
        {
            int ele = arr2[i];
            int cnt = mp[ele];
            while(cnt!=0)
            {
                ans.push_back(ele);
                cnt--;
            }
            mp.erase(ele);
        }

        for(auto i: mp)
        {
            int cnt = i.second;
            while(cnt!=0)
            {
                ans.push_back(i.first);
                cnt--;
            }
        }

        return ans;
    }
};