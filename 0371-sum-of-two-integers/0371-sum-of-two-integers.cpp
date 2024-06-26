class Solution {
public:
    int getSum(int a, int b) {
        while(b!=0)
        {
            // carry now contains set f set bits. carry contributes to the next bit so it will be left shifted later
            int carry = a&b;

            // sum of bits of a and b where atleast one of the bits is not set
            a = a^b;

            // Carry is shifted by one so that adding it to a gives the required sum
            b = carry<<1;
        }

        return a;
    }
};