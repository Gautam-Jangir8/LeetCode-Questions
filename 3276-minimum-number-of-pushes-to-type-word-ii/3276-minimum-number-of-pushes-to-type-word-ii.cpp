class Solution {
public:
    int minimumPushes(string word) {
        vector<int>vec(26, 0);

        // All the elements frequency is stored in the vector
        for(int i=0; i<word.size(); i++) {
            vec[word[i]-'a']++;
        }

        int ans = 0;
        sort(vec.begin(), vec.end(), greater<int>());
        int cnt = 0;
        int temp = 1;
        for(auto i: vec) {
            if(cnt==8) {
                temp++;
                cnt = 0;
            }
            if(i>0) {
                cnt++;
                ans+=(temp*i);
            }
        }

        return ans;
    }
};