class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();

        unordered_map<char, int>mp;
        for(auto i: words) {
            for(auto j: i) {
                mp[j]++;
            }
        }

        for(auto i: mp) {
            if(i.second%n!=0) {
                return false;
            } 
        }

        return true;
    }
};