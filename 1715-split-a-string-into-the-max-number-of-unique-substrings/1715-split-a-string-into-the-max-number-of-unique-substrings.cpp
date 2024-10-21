class Solution {
public:
    void recursion(int idx, string &s, unordered_set<string>&set, int &maxCount) {
        if(idx==s.length()) {
            maxCount = max(maxCount, (int)set.size());
            return;
        }

        string temp = "";
        for(int i=idx; i<s.length(); i++) {
            temp+=s[i];
            if(set.find(temp)==set.end()) {
                set.insert(temp);
                recursion(i+1, s, set, maxCount);
                set.erase(temp);
            }
        }
    }

    int maxUniqueSplit(string s) {
        unordered_set<string>set;
        int maxCount = 0;

        recursion(0, s, set, maxCount);

        return maxCount;
    }
};