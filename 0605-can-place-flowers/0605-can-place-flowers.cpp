class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i=0;
        int count = 0; 

        while(i<flowerbed.size()) {
            if(flowerbed[i]==0)
            {
                // Check the previous and next position, only when they are in bounds
                bool leftEmpty = (i==0) || (flowerbed[i-1]==0);
                bool rightEmpty = (i==flowerbed.size()-1) || (flowerbed[i+1]==0);

                if (leftEmpty && rightEmpty) {
                    count++;
                    cout<<count;
                    flowerbed[i] = 1;  // Place a flower here
                }
            }

            if(count>=n) {
                return true;
            }

            i++; // Move to next step
        }

        return count>=n;
    }
};