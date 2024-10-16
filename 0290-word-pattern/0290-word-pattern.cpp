class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
        unordered_map<string, char>mp;
        unordered_set<char>set;

        stringstream ss(s);
        string word;// access each word of the string in the form of tokens and process it

        int i = 0;
        int cntWords = 0;
        while (ss >> word) {
            if(mp.find(word)!=mp.end()) {
                if(mp[word]!=pattern[i]) {
                    return false;
                }
            } else {
                if(set.find(pattern[i])!=set.end()) {
                    return false;
                }
                mp[word] = pattern[i];
                set.insert(pattern[i]);
            }
            i++;
            cntWords++;
        }       

        if(cntWords!=pattern.size()) {
            return false;
        }
        

        return true;
    }
};