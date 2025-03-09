class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int res = 0;
        int prev = colors[0];
        int alternatingCount = 1;
        for (int idx = 1; idx < n + k - 1; idx++) {
            int i = idx % n;
            if (colors[i] == prev) {
                alternatingCount = 1;
                continue;
            }
            alternatingCount++;
            if (alternatingCount >= k)
                res++;
            prev = colors[i];
        }
        return res;
    }
};