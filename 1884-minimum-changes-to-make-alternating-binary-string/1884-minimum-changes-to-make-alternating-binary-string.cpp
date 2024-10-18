class Solution {
public:
    int minOperations(string s) {
        string temp1 = "0";
        string temp2 = "1";

        for(int i=1; i<s.length(); i++) {
            if(temp1.back()=='0') {
                temp1.push_back('1');
            } else {
                temp1.push_back('0');
            }

            if(temp2.back()=='0') {
                temp2.push_back('1');
            } else {
                temp2.push_back('0');
            }
        }

        int ans1 = 0, ans2 = 0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]!=temp1[i]) {
                ans1++;
            }
            if(s[i]!=temp2[i]) {
                ans2++;
            }
        }

        return min(ans1, ans2);
    }
};