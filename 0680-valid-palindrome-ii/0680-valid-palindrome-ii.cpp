class Solution {
public:
    bool isPalindromeRange(string s, int start, int end) {
        while (start <= end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        bool del = false;

        int start = 0;
        int end = s.size()-1;

        while(start<=end) {
            if(s[start]==s[end]) {
                start++;
                end--;
            } else 
                // Try skipping either the character at start or at end
            return isPalindromeRange(s, start + 1, end) || isPalindromeRange(s, start, end - 1);
        }

        return true;
    }
};