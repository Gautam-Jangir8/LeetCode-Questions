class Solution {
public:
    long long minimumSteps(string s) 
    {
        long long ans = 0;
        int l1 = 0, r1 = s.length()-1;

        while(l1<r1) {
            if(s[l1]=='1') {
                if(s[r1]=='0') {
                    ans+=(r1-l1);
                    l1++;
                }
                r1--;
            } else { // If l1 is 0 means just increment
                if(s[r1]=='1') {
                    r1--;
                }
                l1++;
            }
        }

        return ans;
    }
};