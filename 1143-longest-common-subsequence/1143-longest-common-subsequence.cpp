class Solution {
public:
    int mem[1001][1001];
    int m, n;
    int solve(string& s1, string& s2, int i, int j) {
        if (i >= m || j >= n)
            return 0;
        if (mem[i][j] != -1)
            return mem[i][j];
        if (s1[i] == s2[j])
            return mem[i][j] = 1 + solve(s1, s2, i + 1, j + 1);
        return mem[i][j] =
                   max(solve(s1, s2, i + 1, j), solve(s1, s2, i, j + 1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        m = text1.length(), n = text2.length();
        memset(mem, -1, sizeof(mem));
        return solve(text1, text2, 0, 0);
    }
};