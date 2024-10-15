class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        stack<int>s;
        vector<int>ans(n, -1);

        s.push(arr[n-1]);
        for(int i=n-2; i>=0; i--) {
            if(s.empty()) {
                arr[i] = -1;
            } else {
                ans[i] = s.top();
            }
            if(arr[i]>s.top()) {
                s.push(arr[i]);
            }
        }

        return ans;
    }
};