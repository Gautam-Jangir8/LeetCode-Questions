class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        int power = 0;
        while(num>0) {
            if((num&1)==0) {
                ans = ans+pow(2, power);
            }
            power++;
            num = num>>1;
        }

        return ans;
    }
};