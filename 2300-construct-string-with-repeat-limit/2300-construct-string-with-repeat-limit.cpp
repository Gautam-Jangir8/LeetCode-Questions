class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int>freq(26, 0);
        priority_queue<pair<char, int>>pq;
        for(auto i: s) {
            freq[i-'a']++;
        }
        for(int i=0; i<26; i++) {
            if(freq[i]>0) {
                pq.push({'a'+i, freq[i]});
            }
        }

        string ans = "";
        while(!pq.empty()) {
            auto [ch, count] = pq.top();
            pq.pop();
            int used = min(repeatLimit, count);
            ans.append(used, ch);
            count -= used;

            if(count>0) {
                if(pq.empty()) {
                    break;
                }

                auto [nextCh, nextCount] = pq.top();
                pq.pop();
                ans+=nextCh;
                nextCount--;
                
                if(nextCount>0) {
                    pq.push({nextCh, nextCount});
                }
                pq.push({ch, count});
            }
        }

        return ans;
    }
};