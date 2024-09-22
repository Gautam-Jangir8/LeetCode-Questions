class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        vector<int>lps(n, 0);
        int pre = 0, suf = 1;

        while(suf<n) {
            if(s[pre]==s[suf]) {
                lps[suf] = pre+1;
                pre++;
                suf++;
            } else {
                if(pre==0) {
                    lps[suf] = 0;
                    suf++;
                } else {
                    pre = lps[pre-1];
                }
            }
        }

        int len = lps[n-1];
        return s.substr(0, len);
    }
};