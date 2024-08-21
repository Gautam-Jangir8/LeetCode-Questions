class Solution {
public:
    void recursion(int idx, int n, string &digits, vector<string>&ans, vector<pair<int, string>>&vec, string temp) {
        if(idx==n) {
            ans.push_back(temp);
            return;
        }

        int digit = digits[idx]-'0';
        string str = vec[digit-2].second;
        for(int i=0; i<str.length(); i++) {
            temp.push_back(str[i]);
            recursion(idx+1, n, digits, ans, vec, temp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        // If the number of digits are zero 
        if(n==0) {
            return {};
        }

        vector<pair<int, string>>vec = {{2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};

        vector<string>ans; 
        recursion(0, n, digits, ans, vec, "");

        return ans;
    }
};