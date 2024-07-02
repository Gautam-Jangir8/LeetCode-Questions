class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int ans = 0;
        vector<int>temp = heights;
        sort(temp.begin(), temp.end());

        for(int i=0; i<heights.size(); i++)
        {
            if(heights[i]!=temp[i])
            {
                ans++;
            }
        }
        return ans;
    }
};