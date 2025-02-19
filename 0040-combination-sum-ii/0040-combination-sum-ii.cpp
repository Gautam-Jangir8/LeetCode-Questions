class Solution {
public:
    void recursion(int idx, vector<int>& candidates, int target, vector<vector<int>>&ans, vector<int>&temp) {
        // Base Case
        if(target==0) { 
            ans.push_back(temp);
            return;
        }
        
        for(int i=idx; i<candidates.size(); i++) {
            if(i>idx && candidates[i]==candidates[i-1]) {
                continue;
            }
            if(candidates[i]>target) {
                break;
            }
            temp.push_back(candidates[i]);
            recursion(i+1, candidates, target-candidates[i], ans, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;

        recursion(0, candidates, target, ans, temp);

        return ans;
    }
};