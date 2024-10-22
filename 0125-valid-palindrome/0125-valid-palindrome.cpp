class Solution {
public:
    bool isPalindrome(string s) {
        string ans = "";

        for(int i=0; i<s.length(); i++) {
            if(isalpha(s[i])) {
                ans+=tolower(s[i]);
            }
            if(isdigit(s[i])) {
                ans+=(s[i]);
            }
        }

        int i=0, j=ans.length()-1;
        while(i<j) {
            if(ans[i]!=ans[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};