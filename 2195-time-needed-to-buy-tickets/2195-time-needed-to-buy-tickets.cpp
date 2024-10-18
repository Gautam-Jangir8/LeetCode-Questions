class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        deque<int>dq;

        int ans = 0;
        for(int i=0; i<n; i++) {
            dq.push_back(tickets[i]);
        }
        // Shifting first k elements
        while(k>0) {
            int temp = dq.front();
            dq.pop_front();
            ans++;
            temp--;
            if(temp>0) {
                dq.push_back(temp);
            }
            k--;
        }

        // Now the element to be removed is present at the front of the queue
        while(true) {
            if(dq.front()==1) {
                return ans+1;
            }
            int cnt = dq.size();
            for(int i=0; i<cnt; i++) {
                int temp = dq.front();
                dq.pop_front();
                ans++;
                temp--;
                if(temp>0) {
                    dq.push_back(temp);
                }
            }
        }

        return -1;
    }
};