class Solution {
public:
    void merge(int start, int mid, int end, vector<int>&nums) {
        vector<int>nums1(mid-start+1);
        vector<int>nums2(end-mid);

        for(int i=start; i<=mid; i++) {
            nums1[i-start] = nums[i];
        }
        for(int i=mid+1; i<=end; i++) {
            nums2[i-(mid+1)] = nums[i];
        }

        int i=0, j=0, k=start;
        while(i<nums1.size() && j<nums2.size()) {
            if(nums1[i]<nums2[j]) {
                nums[k] = nums1[i];
                i++;
                k++;
            } else {
                nums[k] = nums2[j];
                j++;
                k++;
            }
        }

        while(i<nums1.size()) {
            nums[k] = nums1[i];
            i++;
            k++;
        }
        while(j<nums2.size()) {
            nums[k] = nums2[j];
            j++;
            k++;
        }
    }

    void mergeSort(int start, int end, vector<int>&nums) {

        if(start<end) {
            int mid = start+(end-start)/2;

            mergeSort(start, mid, nums);
            mergeSort(mid+1, end, nums); 
            merge(start, mid, end, nums);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(0, n-1, nums);

        return nums;
    }
};