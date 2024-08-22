class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int>ans;

        int r1 = 0, c1 = 0, r2= n-1, c2 = m-1;

        while(r1<=r2 && c1<=c2) {
            for(int i=c1; i<=c2; i++) {
                ans.push_back(matrix[r1][i]);
            }
            r1++;
            for(int i=r1; i<=r2; i++) {
                ans.push_back(matrix[i][c2]);
            }
            c2--;

            if(r1>r2 || c1>c2) {
                break;
            }

            for(int i=c2; i>=c1; i--) {
                ans.push_back(matrix[r2][i]);
            }
            r2--;
            for(int i=r2; i>=r1; i--) {
                ans.push_back(matrix[i][c1]);
            }
            c1++;
        }

        return ans;
    }
};