class Solution {
public:
    string recursion(string temp, int n) {
        if(n==0) {
            return temp;
        }

        string rev = temp;
        for(int i=0; i<rev.size(); i++){
            if(rev[i]=='0') {
                rev[i] = '1';
            } else {
                rev[i] = '0';
            }
        }
        reverse(rev.begin(), rev.end());
        temp = temp+"1"+rev;
        return recursion(temp, n-1);
    }

    char findKthBit(int n, int k) {
        string str = recursion("0", n-1);

        return str[k-1];
    }
};