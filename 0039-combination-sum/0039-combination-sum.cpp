class Solution {
public:
    void recursion(int idx, vector<int>& candidates, int target, vector<vector<int>>&ans, vector<int>&temp) {
        // Base Case
        if(target==0) {
            ans.push_back(temp);
            return;
        }
        if(idx < 0) 
        {
            return;
        }

        // NotTake
        recursion(idx-1, candidates, target, ans, temp);
        // Take
        if(target>=candidates[idx]) {
            temp.push_back(candidates[idx]);
            recursion(idx, candidates, target-candidates[idx], ans, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>>ans;
        vector<int>temp;

        recursion(n-1, candidates, target, ans, temp);

        return ans;
    }
};