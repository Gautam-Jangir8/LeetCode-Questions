class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        // In O(1) space complexity 
        int m = 1e3+1;// maximum value of the element +1
        int e=0, o=n;
        for(int i=0; i<2*n; i++)
        {
            if(i%2==0)
            {
                nums[i] += m*(nums[e++]%m);
            }
            else
            {
                nums[i] += m*(nums[o++]%m);
            }
        }

        for(int i=0; i<2*n; i++)
        {
            nums[i] = nums[i]/m;
        }

        return nums;
    }
};

// vector<int> shuffle(vector<int>& nums, int n) {
//         int m=1e3+1;
//         int e=0,o=n;
//         for(int i=0;i<2*n;i++){
//             if(i%2==0) nums[i]+=m*(nums[e++]%m);
//             else nums[i]+=m*(nums[o++]%m);
//         }
//         for(int i=0;i<2*n;i++) nums[i]=nums[i]/m;
//         return nums;   
//     }