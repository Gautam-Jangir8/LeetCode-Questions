class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int ansInt = -1;

        for(int i=0; i<=num.size()-3; i++) {
            if(num[i]==num[i+1] && num[i]==num[i+2]) {
                string str = num.substr(i, 3);
                if(stoi(str)>ansInt) {
                    ansInt = stoi(str);
                    ans = str;
                }
            }
        }

        return ans;
    }
};