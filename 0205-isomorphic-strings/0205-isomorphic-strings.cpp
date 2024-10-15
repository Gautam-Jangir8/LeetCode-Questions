class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) {
            return false;
        }

        int n = s.size();
        unordered_map<char, char>mp;
        unordered_set<char>set;
        for(int i=0; i<n; i++) {
            if(mp.find(s[i])==mp.end()) // First time occurance of char 
            {
                if(set.find(t[i])!=set.end()) {
                    return false;
                }
                mp[s[i]] = t[i];
                set.insert(t[i]);
            } 
            else 
            {
                if(mp[s[i]]!=t[i]) {
                    return false;
                }
            }
        }

        return true;
    }
};