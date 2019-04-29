class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int *target = &nums1[n + m - 1];
        int i = m - 1, j = n - 1;
        while (i >= 0 || j >= 0) {
            if (i < 0) {
                *target-- = nums2[j--];
            } else if (j < 0) {
                *target-- = nums1[i--];
            } else if (nums1[i] > nums2[j]) {
                *target-- = nums1[i--];
            } else {
                *target-- = nums2[j--];
            }
        }
    }
};