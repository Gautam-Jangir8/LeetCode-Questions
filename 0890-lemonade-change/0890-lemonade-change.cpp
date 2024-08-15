class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveD = 0, tenD = 0;

        for(int x: bills) {
            if(x==5) {
                fiveD++;
            } else if(x==10) {
                if(fiveD>0) {
                    fiveD--;
                    tenD++;
                } else {
                    return false;
                }
            } else { // This is for 20 dollar note
                if(fiveD>0 && tenD>0) {
                    fiveD--;
                    tenD--;
                } else if(fiveD>2) {
                    fiveD-=3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};