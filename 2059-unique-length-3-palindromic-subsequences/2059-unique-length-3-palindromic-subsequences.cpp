class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int>first(26, -1), last(26, -1);

        for(int i=0; i<s.length(); i++) {
            if(first[s[i]-'a']==-1) {
               first[s[i]-'a'] = i; 
            }
            last[s[i]-'a'] = i;
        }
        cout<<first[0]<<last[0]<<" ";

        int ans = 0;
        for(int i=0; i<26; i++) {
            if(first[i]!=-1 && last[i]!=-1 && last[i]-first[i]>1) {
                unordered_set<char>set;
                for(int j=first[i]+1; j<last[i]; j++) {
                    set.insert(s[j]);
                }
                ans+=set.size();
            }
        }

        return ans;
    }
};