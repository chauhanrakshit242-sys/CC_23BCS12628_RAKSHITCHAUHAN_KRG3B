class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        // Binary search on smaller array
        if (m > n)
            return findMedianSortedArrays(nums2, nums1);

        int size = (n + m + 1) / 2;

        int left = 0;
        int right = m;

        while (left <= right) {

            int mid = (left + right) / 2; // elements taken from nums2

            int left_arr_a = size - mid;  // elements taken from nums1

            int a_left =
                (left_arr_a == 0) ? INT_MIN : nums1[left_arr_a - 1];

            int a_right =
                (left_arr_a == n) ? INT_MAX : nums1[left_arr_a];

            int b_left =
                (mid == 0) ? INT_MIN : nums2[mid - 1];

            int b_right =
                (mid == m) ? INT_MAX : nums2[mid];

            if (a_left <= b_right && b_left <= a_right) {

                if ((n + m) % 2)
                    return max(a_left, b_left);

                return (max(a_left, b_left) +
                        min(a_right, b_right)) / 2.0;
            }

            if (a_left > b_right) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return 0;
    }
};