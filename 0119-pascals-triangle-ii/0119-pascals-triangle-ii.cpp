class Solution {
public:
    int nCr(int n, int r) {
        long long ans = 1;

        for(int i=0; i<r; i++) {
            ans*=n-i;
            ans/=i+1;
        }

        return (int)ans;
    }

    vector<int> getRow(int rowIndex) {
        vector<int>ans;
        for(int i=0; i<=rowIndex; i++) {
            ans.push_back(nCr(rowIndex, i)); 
        }

        return ans;
    }
};