class Solution {
public:
long long maxPoints(vector<vector<int>>& points) {
    int n = points.size();  // number of rows
    int m = points[0].size();  // number of columns

    // Initializing previous with the first row
    vector<long long> prev(m);
    for(int col = 0; col < m; col++) {
        prev[col] = points[0][col];
    }

    // Traversing all the rows
    for(int i = 1; i < n; i++) {
        vector<long long> left(m, 0);
        vector<long long> right(m, 0);

        // Calculate left array
        left[0] = prev[0];
        for(int j = 1; j < m; j++) {
            left[j] = max(prev[j], left[j - 1] - 1);
        }

        // Calculate right array
        right[m - 1] = prev[m - 1];  // Fixing the indexing here
        for(int j = m - 2; j >= 0; j--) {
            right[j] = max(prev[j], right[j + 1] - 1);
        }

        // Calculate current row's points
        vector<long long> curr(m);  // Fixing the size of curr to 'm'
        for(int j = 0; j < m; j++) {
            curr[j] = points[i][j] + max(left[j], right[j]);
        }

        prev = curr;  // Update previous row for the next iteration
    }

    // Return the maximum points achievable
    return *max_element(begin(prev), end(prev));
}
};