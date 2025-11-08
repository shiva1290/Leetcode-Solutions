class Solution {
public:
    int totalFruit(vector<int>& nums) {
     int fruit1 = nums[0], fruit2 = -1;
        int firstIndex = 0, secondIndex = -1;
        int i = 0;
        int maxTotal = 1;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] == fruit1) {
                firstIndex = j;
            } else if (nums[j] == fruit2) {
                secondIndex = j;
            } else {
                if (firstIndex < secondIndex) {
                    i = firstIndex + 1;
                    fruit1 = nums[j];
                    firstIndex = j;
                } else {
                    i = secondIndex + 1;
                    fruit2 = nums[j];
                    secondIndex = j;
                }
            }
            maxTotal = max(maxTotal, j - i + 1);
        }
        return maxTotal;
    }
};