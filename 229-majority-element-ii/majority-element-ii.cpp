class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int fcounter = 1;
        int fele = nums[0];
        int scounter = 0;
        int sele = INT_MIN;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == fele) {
                fcounter++;
            }
            else if (nums[i] == sele) {
                scounter++;
            } else if (fcounter == 0 && nums[i] != sele) {
                fele = nums[i];
                fcounter++;
            } else if (scounter == 0 && nums[i] != fele) {
                sele = nums[i];
                scounter++;
            } else {
                fcounter--;
                scounter--;
            }
        }
        int i = 0;
        int j = 0;
        for (auto num : nums) {
            if (num == sele)
                i++;
            else if (num == fele)
                j++;
        }
        if (i <= nums.size() / 3.0 && j <= nums.size() / 3.0)
            return {};
        if (sele == INT_MIN || (i <= nums.size() / 3.0))
            return {fele};
        if (j <= nums.size() / 3.0)
            return {sele};
        return {fele, sele};
    }
};