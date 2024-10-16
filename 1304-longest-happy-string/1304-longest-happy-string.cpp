class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>>pq;
        if(a>0) pq.push({a, 'a'});
        if(b>0) pq.push({b, 'b'});
        if(c>0) pq.push({c, 'c'});

        string result = "";

        while(!pq.empty()) {
            pair<int, char>p1 = pq.top();
            int count1 = p1.first;
            int char1 = p1.second;
            pq.pop();

            // Checking if last two char in the string are same
            if(result.size()>=2 && result.back()==char1 && result[result.size()-2]==char1) {
                if(pq.empty()) { // No valid char left, as pq is empty
                    break;
                }

                // Get the second most char
                auto [count2, char2] = pq.top();
                pq.pop();
                // Add the second character to avoid consecutive repetation
                result+=char2;
                count2--;

                if(count2>0) {
                    pq.push({count2, char2});
                }

                // Push the most frequent char for later use
                pq.push({count1, char1});
            } else {
                result+=char1;
                count1--;

                if(count1>0) {
                    pq.push({count1, char1});
                }
            }
        }
        
        return result;
    }
};