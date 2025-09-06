class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        unordered_map<int, int> indexMap;
        vector<int> result;

        for (int i = 0; i < n2; i++) {
            indexMap[nums2[i]] = i;
        }

        for (int i = 0; i < n1; i++) {
            int element = nums1[i];
            int startIndex = indexMap[element]; 
            bool found = false;

            for (int j = startIndex + 1; j < n2; j++) {
                if (nums2[j] > element) {
                    result.push_back(nums2[j]);
                    found = true;
                    break;
                }
            }

            if (!found) {
                result.push_back(-1);
            }
        }

        return result;
    }
};
