class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=n+m-1;
        int j=0;
        while(i>=m) {
            nums1[i] = nums2[j]; 
            j++;
            i--;
        }

        sort(nums1.begin(), nums1.end());
    }
};