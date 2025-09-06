class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
           int n1 = arr1.size();
        int n2 = arr2.size();
        int n = (n1 + n2 + 1) / 2;
        if (n1 > n2) return findMedianSortedArrays(arr2, arr1);
        int low = 0;
        int high = n1;
        int ans;
        while (low <= high) {

            int cut1=(low+high)/2;
            int cut2=n-cut1;

            int l1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
            int r1 = (cut1 == n1) ? INT_MAX : arr1[cut1];
            int r2 = (cut2 == n2) ? INT_MAX : arr2[cut2];


            if (l1 > r2) {
                high=cut1-1;
            } else if (l2 > r1) {
                low=cut1+1;
            } else if (l1 <= r2 && l2 <= r1) {
                if ((n1 + n2) % 2 == 0) return (max(l1, l2) + min(r1, r2)) / 2.0;
                return max(l1, l2);
            }
        }
        return -1;
    }
};