class Solution {
public:
    long long minimumSteps(string s) 
    {
        long long ans = 0;
        
        int white = 0;
        for(int i=0; i<s.length(); i++) {
            if(s[i]=='0') { // As zero has to shift number of white time to the left
                ans+=white;
            } else {
                white++;
            }
        }

        return ans;
    }
};