class Solution {
public:
    int dfs(map<int, vector<int>>&mp, vector<int>&informTime, int headId) {
        int maxi = 0;
        if(mp.find(headId)==mp.end()) {
            return maxi;
        }

        for(int i=0; i<mp[headId].size(); i++) {
            maxi = max(maxi, dfs(mp, informTime, mp[headId][i]));
        }
        return maxi+informTime[headId];
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        map<int, vector<int>>mp;
        for(int i=0; i<manager.size(); i++) {
            mp[manager[i]].push_back(i);
        }

        return dfs(mp, informTime, headID);
    }
};