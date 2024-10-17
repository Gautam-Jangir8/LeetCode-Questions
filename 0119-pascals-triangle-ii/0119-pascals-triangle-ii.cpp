class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        ans.push_back(1);
        long long temp = 1;
        for (int i = 0; i < rowIndex; i++)
        {
            temp *= rowIndex-i;
            temp /= i+1;
            ans.push_back((int)temp);
        }

        return ans;
    }
};