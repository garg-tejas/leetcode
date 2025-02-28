class Solution {
public:
    static long long sumRow(long long sum, vector<int>& row) {
        return sum + accumulate(row.begin(), row.end(), 0LL);
    }

    static long long sumSquareElement(long long sum, int x) {
        return sum + (long long)x * x;
    }

    static long long sumSquareRow(long long sum, vector<int>& row) {
        return sum + accumulate(row.begin(), row.end(), 0LL, sumSquareElement);
    }

    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long sqrSum = accumulate(grid.begin(), grid.end(), 0LL, sumSquareRow);
        long long sum = accumulate(grid.begin(), grid.end(), 0LL, sumRow);
        long long n = grid.size() * grid.size();
        long long expSum = n * (n + 1) / 2;
        long long expSqrSum = n * (n + 1) * (2 * n + 1) / 6;
        long long sumDiff = sum - expSum;
        long long sqrDiff = sqrSum - expSqrSum;
        int repeat = (sqrDiff / sumDiff + sumDiff) / 2;
        int missing = (sqrDiff / sumDiff - sumDiff) / 2;
        return {repeat, missing};
    }
};