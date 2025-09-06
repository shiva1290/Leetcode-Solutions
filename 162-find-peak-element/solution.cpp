class Solution {
   public:
    int isPeak(vector<int> &arr, int i) {
        if (arr[i - 1] < arr[i] && arr[i + 1] < arr[i]) return 1;
        else if (arr[i - 1] < arr[i] && arr[i + 1] > arr[i]) return 2;
        return 0; 
    }
    int findPeakElement(vector<int> &arr) {
        int low = 1;
        int n=arr.size();
        int high = arr.size() - 2;
        int ans = 0;
        if(n==1) return 0;
        if(arr[0]>arr[1]) return 0;
        if(arr[n-1]>arr[n-2]) return n-1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int res = isPeak(arr, mid);
            if (res == 1) return mid;
            else if (res == 2) {
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return -1;
    }
};