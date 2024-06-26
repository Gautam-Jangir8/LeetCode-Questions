class Solution {
public:
    int getSum(int a, int b) {
         //code here
        int val1=a^b;
        int val2=(a&b)<<1;
        int value=val1+val2 ;
        return value;
    }
};