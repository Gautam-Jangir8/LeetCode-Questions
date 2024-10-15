class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, int>mp;

        string ans = "";
        for(int i=0; i<n; i++) {
            string str = strs[i];

            string temp = "";
            for(int j=0; j<str.length(); j++) {
                temp+=str[j];
                mp[temp]++;

                if(mp[temp]==n) {
                    if(temp.length() > ans.length()) {
                        ans = temp;
                    }
                }
            }
        }

        return ans;
    }
};