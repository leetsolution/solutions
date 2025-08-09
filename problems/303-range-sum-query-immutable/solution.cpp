class NumArray {
public:
    vector<long long> prefixSum;
    NumArray(vector<int>& nums) {
        long long sum = 0;
        for(int num: nums){
            sum += num;
            prefixSum.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return prefixSum[right];
        return prefixSum[right] - prefixSum[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */