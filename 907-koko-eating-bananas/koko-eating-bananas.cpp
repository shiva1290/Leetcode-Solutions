class Solution {
public:
    long long hours(vector<int>&piles,int mid){
        long long ans=0;
        for(int i=0;i<piles.size();i++){
            ans+=ceil(piles[i]/static_cast<double>(mid));
        }
        return ans;
    }

    int binarySearch(int low, int high, vector<int>& piles, int h) {
        while (low <= high) {
            long long mid =1LL* low + (high - low) / 2;
            long long ans = hours(piles, mid);
            if (ans > h) {
                low=mid+1;
            } else if (ans <= h) {
                high=mid-1;
            }
        }
        return low;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = INT_MIN;
        for (auto num : piles) {
            maxi = max(maxi, num);
        }
        return binarySearch(1, maxi, piles, h);
    }
};