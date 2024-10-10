class Solution {
public:
    int recursion(int n, int cnt, int c) {
        if(cnt>n) {
            return 1e7;
        } 
        if(cnt==n) {
            return 0; // No further steps is required we have reached our destination
        }

        int ans = 1e7;
        if(n%cnt==0) {
            ans = min(ans, recursion(n, n, c)+n/cnt);
        }

        ans = min(ans, recursion(n, cnt*2, cnt)+2);// update cnt(Pasting), as well as last copied(Copied present char)
        ans = min(ans, recursion(n, cnt+c, c)+1);// Only updated count by (Pasting) last copied i.e. c 

        return ans;
    }

    int minSteps(int n) {
        // One size is already present, so retun 0 steps
        if(n==1) {
            return 0;
        }

        return recursion(n, 1, 1) + 1;
    }
};