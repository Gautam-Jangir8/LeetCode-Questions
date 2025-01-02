class Solution {
public:
    int maxScore(string s) {
        int oneCount = 0;
        for(auto i: s) {
            if(i=='1') {
                oneCount++;
            }
        }

        int ans = 0;
        int zeroCount = 0;
        for(int i=0; i<s.size()-1; i++) {
            if(s[i]=='0') {
                zeroCount++;
                ans = max(ans, zeroCount+oneCount);
            } else {
                oneCount--;
                ans = max(ans, zeroCount+oneCount);
            }
        }

        return ans;
    }
};