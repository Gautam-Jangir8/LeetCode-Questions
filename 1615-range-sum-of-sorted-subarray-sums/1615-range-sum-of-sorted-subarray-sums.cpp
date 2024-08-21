class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int mod = 1e9+7;
        // Initialize the Min Heap to track the smaller elements
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

        // Pushing all the elements in the Priority Queue
        for(int i=0; i<n; i++) {
            pq.push({nums[i], i+1});
        }

        long long res = 0;
        for(int i=1; i<=right; i++) {
            auto x = pq.top();
            pq.pop();

            if(left<=i) {
                res+=x.first;
            }
            if(x.second<n) {
                x.first+=nums[x.second];
                x.second++;
                pq.push(x);
            }
        }

        return res%mod;
    }
};