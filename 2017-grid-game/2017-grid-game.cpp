class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();

        vector<vector<long long>> prefixSum(2, vector<long long>(n, 0));

        prefixSum[0][n - 1] = grid[0][n - 1];
        prefixSum[1][0] = grid[1][0];

        for (int i = n - 2; i >= 1; --i) {
            prefixSum[0][i] = grid[0][i] + prefixSum[0][i + 1];
        }

        for (int i = 1; i < n - 1; ++i) {
            prefixSum[1][i] = grid[1][i] + prefixSum[1][i - 1];
        }

        long long result = LONG_LONG_MAX;

        for (int i = 0; i < n; ++i) {
            long long firstRow = (i == n - 1) ? 0 : prefixSum[0][i + 1];
            long long secondRow = (i == 0) ? 0 : prefixSum[1][i - 1];

            result = min(result, max(firstRow, secondRow));
        }

        return result;
    }
};