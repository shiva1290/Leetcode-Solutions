class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(),
             [](auto& a, auto& b) { return a[1] > b[1]; });
    //We use custom comparator to sort by descending value (unit size)
        int totalUnits = 0;
    //Then i'll keep picking until capacity remains
        for (auto& box : boxTypes) {
            int count = min(truckSize, box[0]); 
            totalUnits += count * box[1];
            truckSize -= count;
            if (truckSize == 0)
                break; 
        }
        return totalUnits;
    }
};