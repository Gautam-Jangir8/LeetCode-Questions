class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        int cntSet = 0;
        while(n>0)
        {
            if(n&1==1)
            {
                cntSet++;
            }
            n = n>>1;
        }

        if(cntSet==1)
        {
            return true;
        }
        return false;
    }
};