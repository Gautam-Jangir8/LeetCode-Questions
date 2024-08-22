class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>>direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        // Total number of cells to insert in the answer
        int n = rows*cols;
        vector<vector<int>>ans(n, vector<int>(2, 0));
        ans[0][0] = rStart;
        ans[0][1] = cStart;

        // As one value is alreadyy inserted
        int cnt = 1;
        // Har 2 direction mai move karna ka baad step change hoga
        int step = 1;
        int index = 0;// index is for the direction
        while(cnt<n) {
            // Means we have to perform two operation then increase step value
            for(int times=0; times<2; times++) {
                int dirR = direction[index%4][0];
                int dirC = direction[index%4][1];
                // Now in each direction we have to traveral step 
                for(int i=0; i<step; i++) {
                    rStart+=dirR;
                    cStart+=dirC;
                    if(rStart>=0 && rStart<rows && cStart>=0 && cStart<cols) {
                        ans[cnt][0] = rStart;
                        ans[cnt][1] = cStart;
                        cnt++;
                    }
                }
                index++;
            }   
            step++;
        }

        return ans;
    } 
};