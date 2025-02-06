class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, int>trustOn;
        unordered_map<int, int>trustedBy;

        for(int i=0; i<trust.size(); i++) {
            trustOn[trust[i][1]]++;
            trustedBy[trust[i][0]]++;
        }

        for(int i=1; i<=n; i++) {
            if(trustOn[i]==n-1 && trustedBy.find(i)==trustedBy.end()) {
                return i;
            }
        }

        return -1;
    }
};