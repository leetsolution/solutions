class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people, 0);
        int give = 1;
        int i = 0;
        while (candies > 0) {
            if (candies >= give) {
                ans[i] += give;
                candies -= give;
                give++;
            } else {
                ans[i] += candies;
                candies = 0;
            }
            i = (i + 1) % num_people;
        }
        return ans;
    }
};