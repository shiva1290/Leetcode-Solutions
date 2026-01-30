class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ansArr;

        for (int i = 0; i < spells.size(); i++) {
            int low = 0;
            int high = potions.size() - 1;
            int mid;
            while (low <= high) {
                mid = low + (high - low) / 2;
                long long ans =1LL * spells[i] * potions[mid];
                if (ans >= success) {
                    high = mid-1;
                } else if (ans < success) {
                    low = mid + 1;
                } 
            }
            ansArr.push_back(potions.size()-low);
        }
        return ansArr;
    }
};