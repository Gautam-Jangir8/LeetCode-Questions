class Solution {
public:
    int maximumSwap(int num) {
        // Converting number to string for easier digit manipulation
        string numStr = to_string(num);
        int n = numStr.size();

        // Store the last occurance of each digit (0-9)
        vector<int>last(10, -1);
        for(int i=0; i<n; i++) {
            last[numStr[i]-'0'] = i;
        }

        // Traverse each digit from left to right
        for(int i=0; i<n; i++) {
            // Check if any larger digit appearing later
            for(int d=9; d>numStr[i]-'0'; d--) {
                if(last[d]>i) {
                    // Swap the current digit with the larger one
                    swap(numStr[i], numStr[last[d]]);
                    return stoi(numStr);// Convert back to number and return 
                }
            }
        } 

        // If no Swap was made return the original number
        return num;
    }
};