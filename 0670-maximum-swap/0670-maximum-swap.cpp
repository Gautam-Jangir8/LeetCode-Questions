class Solution {
public:
    int maximumSwap(int num) {
        int res = num;
        vector<int>number;
        while(num>0) {
            number.push_back(num%10);
            num = num/10;
        }

        reverse(number.begin(), number.end());

        for(int i=0; i<number.size()-1; i++) {
            int maxiRight = number[i];
            int maxiIndex = -1;
            for(int j=i+1; j<number.size(); j++) {
                if(number[j]>=maxiRight && number[i]!=number[j]) { // So that we can swap last largest
                    maxiRight = number[j];
                    maxiIndex = j;
                }
            }
            if(maxiIndex!=-1) {
                swap(number[i], number[maxiIndex]);
                break;
            }
        }

        int ans = 0;
        for(int i=0; i<number.size(); i++) {
            ans = ans*10 + number[i];
        }

        return max(ans, res);
    }
};