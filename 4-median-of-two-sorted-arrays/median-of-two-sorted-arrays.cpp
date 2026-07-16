class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int total = n1 + n2;
        
        // Track the current element and previous element for even-length averages
        int curr = 0, prev = 0; 
        int i = 0, j = 0;
        
        // Loop exactly until we reach the median position
        for (int counter = 0; counter <= total / 2; counter++) {
            prev = curr; // Save the last element before moving to the next
            
            // Safely move the pointers without going out of bounds
            if (i < n1 && (j >= n2 || nums1[i] <= nums2[j])) {
                curr = nums1[i];
                i++;
            } else {
                curr = nums2[j];
                j++;
            }
        }
        
        // If odd, return the middle element. If even, return the average of the two middle elements.
        if (total % 2 != 0) {
            return curr;
        }
        return (double)(prev + curr) / 2.0;
    }
};