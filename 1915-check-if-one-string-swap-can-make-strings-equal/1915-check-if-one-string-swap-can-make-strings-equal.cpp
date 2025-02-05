class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        unordered_map<char, int>mp;
        int cnt = 0;
        for(int i=0; i<s1.size(); i++) {
            if(s1[i]!=s2[i]) {
                cnt++;
                mp[s1[i]]++;
                mp[s2[i]]--;

                if(mp[s1[i]]==0) {
                    mp.erase(s1[i]);
                }
                if(mp[s2[i]]==0) {
                    mp.erase(s2[i]);
                }
            }

            if(cnt>2) {
                return false;
            }
        }

        if(cnt==1 || mp.size()>0) {
            return false;
        } 
        return true;
    }
};