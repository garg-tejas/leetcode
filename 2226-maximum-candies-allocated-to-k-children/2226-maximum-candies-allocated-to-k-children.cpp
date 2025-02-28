class Solution {
public:
    bool canDistribute(vector<int>& candies, long long k, int mid) {
        long long count = 0;
        for (auto candy : candies) {
            count += (candy / mid);
        }
        return count >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = accumulate(candies.begin(), candies.end(), 0LL);
        if (sum < k) return 0;
        int left = 1, right = *max_element(candies.begin(), candies.end());
        int res = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canDistribute(candies, k, mid)) {
                res = mid;
                left = mid + 1; 
            } else {
                right = mid - 1; 
            }
        }
        return res;
    }
};