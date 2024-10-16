class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int>mp;
        unordered_map<char, int>mp2;
        for(int i=0; i<text.length(); i++) {
            mp[text[i]]++;
        }

        string s = "balloon";
        for(char i: s) {
            mp2[i]++;
        }

        int mini = INT_MAX;
        for(auto i: mp2) {
            mini = min(mini, mp[i.first]/i.second);
        }

        return mini;
    }
};