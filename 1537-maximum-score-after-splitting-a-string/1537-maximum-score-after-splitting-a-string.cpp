class Solution {
public:
    int maxScore(string s) {
        int cntOnes = 0;

        for(int i=0; i<s.length(); i++) {
            if(s[i]=='1') {
                cntOnes++;
            }
        }

        int ans = 0;
        int cntZeros = 0;
        for(int i=0; i<s.length()-1; i++) {
            if(s[i]=='0') {
                cntZeros++;
            } else {
                cntOnes--;
            }
            ans = max(ans, cntZeros + cntOnes);
        }

        return ans;
    }
};