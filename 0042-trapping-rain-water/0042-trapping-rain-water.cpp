class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>prevGreater(n, 0), nextGreater(n, 0);

        prevGreater[0] = height[0];
        for(int i=1; i<n; i++) {
            prevGreater[i] = max(prevGreater[i-1], height[i]);
        }
        nextGreater[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--) {
            nextGreater[i] = max(nextGreater[i+1], height[i]);
        }

        int ans = 0;
        for(int i=1; i<n-1; i++) {
            ans += min(prevGreater[i], nextGreater[i])-height[i];
        }

        return ans;
    }
};