class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int>mp;

        for(int i=0; i<order.size(); i++) {
            mp[order[i]] = i;
        }

        vector<vector<string>>ans;
        for(int i=0; i<words.size(); i++) {
            string str = words[i];

            for(int j=0; j<str.size(); j++) {
                str[j] = 'a'+mp[str[j]];
            }
            ans.push_back({str, words[i]});
        }

        sort(ans.begin(), ans.end());

        for(int i=0; i<ans.size(); i++) {
            if(words[i]!=ans[i][1]) {
                return false;
            }
        }

        return true;
    }
};