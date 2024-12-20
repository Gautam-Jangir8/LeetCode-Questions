class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int ans = 0;
        map<int, vector<int>>mp;
        for(int i=0; i<manager.size(); i++) {
            mp[manager[i]].push_back(i);
        }

        queue<pair<int, int>>q;
        q.push({headID, informTime[headID]});
        while(!q.empty()) {
            pair<int, int>p = q.front();
            q.pop();
            ans = max(ans, p.second);

            for(auto i: mp[p.first]) {

                if(mp.find(i)!=mp.end()) {
                    q.push({i, p.second+informTime[i]});
                }
            }
        }

        return ans;
    }
};