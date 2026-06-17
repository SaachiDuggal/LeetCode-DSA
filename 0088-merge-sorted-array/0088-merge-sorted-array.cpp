class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;      // Pointer for the end of valid elements in nums1
        int j = n - 1;      // Pointer for the end of nums2
        int k = m + n - 1;  // Pointer for the last position in nums1's total capacity

        // Merge from right to left, putting the larger elements at the end
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        // Copy any remaining elements from nums2 if nums1 finishes first
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};