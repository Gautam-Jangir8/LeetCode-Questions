class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int>mp;
        unordered_set<string>set;
        for(int i=0; i<paths.size(); i++) {
            mp[paths[i][0]]++;
            set.insert(paths[i][0]);
            mp[paths[i][1]]++;
        }

        for(auto i: mp) {
            if(i.second==1 && set.find(i.first)==set.end()) {
                return i.first;
            }
        }

        return "-1";
    }
};