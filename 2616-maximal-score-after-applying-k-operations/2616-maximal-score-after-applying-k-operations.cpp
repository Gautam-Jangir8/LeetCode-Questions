class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;

        for(int i=0; i<nums.size(); i++) {
            pq.push(nums[i]);
        }

        long long score = 0;
        while(k>0) {
            int ele = pq.top();
            pq.pop();
            k--;

            score+=ele;
            pq.push(ceil((ele+2)/3));// Ele+2 for the proper rounding off in case 7/3 int/int = 2
        }

        return score;
    }
};