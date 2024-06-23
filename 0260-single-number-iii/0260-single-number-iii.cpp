class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int numSum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            numSum = numSum^nums[i];
        }

        // Finding the first set bit of the two different numbers in the array, that will help us to divide the array into two halves
        int cnt = 0;
        while((numSum & 1)==0)
        {
            numSum = numSum>>1;
            cnt++;
        }

        int a = 0, b = 0;

        for(int i=0; i<nums.size(); i++)
        {
            if((nums[i] & (1<<cnt))!=0)
            {
                a = a^nums[i];
            }
            else
            {
                b = b^nums[i];
            }
        }

        return {a, b};
    }
};