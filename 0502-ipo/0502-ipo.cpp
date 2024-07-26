class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>>projects;

        for(int i=0; i<profits.size(); i++) {
            projects.push_back({capital[i], profits[i]});
        }
        sort(projects.begin(), projects.end());

        // We will use max heap to store the profits of the projects we can afford with the current capital.
        priority_queue<int>pq;
        int i = 0;

        while(k>0) {
            while(i<projects.size() && projects[i].first<=w) {
                pq.push(projects[i].second);
                i++;
            }

            // no more affordable projects.
            if(pq.empty()) {
                break;
            }

            w+=pq.top();
            pq.pop();
            k--;
        }

        return w;
    }
};