class Solution {
public:
    bool lemonadeChange(vector<int>& nums) {
        int n = nums.size();
        int count5 = 0;
        int count10 = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 5) {
                count5++;
            } else if (nums[i] == 10) {
                if(count5){
                count10++;
                count5--;
                }
                else return false;
            } 
            else {
                if(count10 && count5){
                    count10--;
                    count5--;
                }
                else if(count5>=3){
                    count5-=3;
                }
                else return false;
            }
        }
        return true;
    }
};