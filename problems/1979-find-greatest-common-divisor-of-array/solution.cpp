class Solution {
public:
    int findGCD(vector<int>& nums) {
        int smallest = nums[0];
        int largest = nums[0];
        for (int num : nums) {
            smallest = min(smallest, num);
            largest = max(largest, num);
        }
        
        while (largest) {
            int temp = largest;
            largest = smallest % largest;
            smallest = temp;
        }
        return smallest;
    }
};