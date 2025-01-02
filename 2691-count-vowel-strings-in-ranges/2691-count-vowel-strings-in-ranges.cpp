class Solution {
public:
    bool isVowelStartEnd(string str) {
        int end = str.size()-1;
        if((str[0]=='a' || str[0]=='e' || str[0]=='i' || str[0]=='o' || str[0]=='u') && (str[end]=='a' || str[end]=='e' || str[end]=='i' || str[end]=='o' || str[end]=='u')) {
            return true;
        }
        return false;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>ans;
        unordered_map<int, int>mp;
        int cnt = 0;
        for(int i=0; i<words.size(); i++) {
            string single = words[i];
            if(isVowelStartEnd(single)) {
                cnt++;
            }
            mp[i] = cnt;
            cout<<mp[i]<<" ";
        }

    

        for(int i=0; i<queries.size(); i++) {
            int start = queries[i][0];
            int end = queries[i][1];

            // if(start==end) {
            //     ans.push_back(0);
            // } else {
            // }
                int temp = start==0 ?  0 : mp[start-1];
                ans.push_back(mp[end]-temp);
        }

        return ans;
    }
};