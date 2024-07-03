class Solution {
public:
    void recursion(int idx, string digits, int n, vector<pair<int, string>>vec, vector<string>&ans, string temp)
    {
        if(idx==n)
        {
            ans.push_back(temp);
            return;
        }
        
        int digit = digits[idx]-'0';
        string s = vec[digit-2].second;
        for(int i=0; i<s.length(); i++)
        {
            temp.push_back(s[i]);
            recursion(idx+1, digits, n, vec, ans, temp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.length()==0)
        {
            return {};
        }

        int N = digits.length();
        vector<pair<int, string>>vec = {{2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"},
            {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};
        vector<string>ans;
        recursion(0, digits, N, vec, ans, "");

        return ans;
    }
};