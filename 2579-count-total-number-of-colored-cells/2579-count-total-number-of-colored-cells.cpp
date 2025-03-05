class Solution {
public:
    long long coloredCells(int n) {
        long long m = n;
        return 1 + (m - 1) * (4 + (m - 2) * 2);
    }
};