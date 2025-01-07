class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), 
             [&](const string &a, const string &b) -> bool {
                 return a.size() > b.size();
             });
        vector<string>ans;

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(words[i].find(words[j])!=string::npos) {
                    ans.push_back(words[j]);
                }
            }
        }

        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};