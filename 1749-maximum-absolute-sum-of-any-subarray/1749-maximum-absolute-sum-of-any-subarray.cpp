class Solution {
public:

    int maxAbsoluteSum(vector<int>& nums) {
        vector<int> prefixSum(nums.size() + 1);
        prefixSum[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefixSum[i + 1] = nums[i] + prefixSum[i];
        }
        int minP = prefixSum[0];
        int maxSum = INT_MIN;
        int maxP = prefixSum[0];
        int minSum = INT_MAX;     
    
        for (auto& num : prefixSum) {
            int price = num - minP;
            maxSum = max(price, maxSum);
            minP = min(minP, num);

            price = num - maxP;
            minSum = min(price, minSum);
            maxP=max(maxP, num);
        }
        return max(abs(minSum), maxSum);
    }
};