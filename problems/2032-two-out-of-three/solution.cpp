class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> result;
        vector<bool> present(101, false);

        for (int i = 1; i <= 100; ++i) {
            int count = 0;
            bool found1 = false;
            bool found2 = false;
            bool found3 = false;

            for (int num : nums1) {
                if (num == i) {
                    found1 = true;
                    break;
                }
            }
            for (int num : nums2) {
                if (num == i) {
                    found2 = true;
                    break;
                }
            }
            for (int num : nums3) {
                if (num == i) {
                    found3 = true;
                    break;
                }
            }

            if (found1) count++;
            if (found2) count++;
            if (found3) count++;

            if (count >= 2 && !present[i]) {
                result.push_back(i);
                present[i] = true;
            }
        }

        return result;
    }
};