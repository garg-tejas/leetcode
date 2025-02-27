class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        vector<vector<int>> dp(n, vector<int>(n, 2));
        int maxLen = 0;
        for (int j = 0; j < n; ++j) {
            mp[arr[j]] = j;
            for (int i = 0; i < j; ++i) {
                int k = (mp.count(arr[j] - arr[i])) ? mp[arr[j] - arr[i]] : -1;
                dp[i][j] =
                    ((arr[j] - arr[i]) < arr[i] && k >= 0) ? dp[k][i] + 1 : 2;
                maxLen = max(dp[i][j], maxLen);
            }
        }
        return maxLen > 2 ? maxLen : 0;
    }
};