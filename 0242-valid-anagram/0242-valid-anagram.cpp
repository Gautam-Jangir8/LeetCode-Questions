class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int>map;
        for(auto i: s) {
            map[i]++;
        }

        for(auto i: t) {
            if(map.find(i)==map.end()) {
                return false;
            }
            map[i]--;
            if(map[i]==0) {
                map.erase(i);
            }
        }

        return map.size()==0 ? true : false;
    }
};