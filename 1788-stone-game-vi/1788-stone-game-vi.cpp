class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        priority_queue<pair<int, pair<int, int>>>pq;

        for(int i=0; i<n; i++) {
            pq.push({aliceValues[i]+bobValues[i], {aliceValues[i], bobValues[i]}});
        }

        int sum1 = 0, sum2 = 0;
        while(!pq.empty()) {
            sum1 += pq.top().second.first;
            pq.pop();

            // If remaning its bob turn
            if(pq.size()>0) {
                sum2 += pq.top().second.second;
                pq.pop();
            }
        }

        return sum1==sum2 ? 0 : sum1>sum2 ? 1 : -1;
    }
};