class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int odd_count = 0;
        int even_count = 0;
        for (int num : nums) {
            if (num % 2 == 0) {
                even_count++;
            } else {
                odd_count++;
            }
        }
        if (abs(odd_count - even_count) > 1) {
            return -1;
        }

        long long ans1 = 0;
        long long ans2 = 0;

        if (even_count >= odd_count) {
            vector<int> temp = nums;
            int even_idx = 0;
            for (int i = 0; i < n; ++i) {
                if (temp[i] % 2 == 0) {
                    swap(temp[i], temp[even_idx]);
                    if(i!= even_idx){
                        int shift = i - even_idx;
                        for(int j = i ;j>even_idx;j--){
                            swap(temp[j],temp[j-1]);
                            ans1++;
                        }
                    }
                    even_idx++;
                }
            }
        } else {
            ans1 = -1;
        }

        if (odd_count >= even_count) {
            vector<int> temp = nums;
            int odd_idx = 0;
            for (int i = 0; i < n; ++i) {
                if (temp[i] % 2 != 0) {
                    swap(temp[i], temp[odd_idx]);
                    if(i!= odd_idx){
                        int shift = i - odd_idx;
                        for(int j = i ;j>odd_idx;j--){
                            swap(temp[j],temp[j-1]);
                             ans2++;
                        }
                    }
                    odd_idx++;
                }
            }
        } else {
            ans2 = -1;
        }
        
        if(ans1 == -1 && ans2 == -1) return -1;
        else if(ans1 == -1) return ans2;
        else if(ans2 == -1) return ans1;
        else return min(ans1, ans2);
    }
};