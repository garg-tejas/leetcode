class Solution {
public:
    int maxSubarraySum(vector<int> &arr) {
        int res = arr[0];
        int maxEnding = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            maxEnding = max(maxEnding + arr[i], arr[i]);
            res = max(res, maxEnding);
        }
        return res;
    }

    int minSubarraySum(vector<int> &arr) {
        int res = arr[0];
        int minEnding = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            minEnding = min(minEnding + arr[i], arr[i]);
            res = min(res, minEnding);
        }
        return res;
    }

    int maxAbsoluteSum(vector<int>& nums) {
        return max(abs(minSubarraySum(nums)), maxSubarraySum(nums));
    }
};