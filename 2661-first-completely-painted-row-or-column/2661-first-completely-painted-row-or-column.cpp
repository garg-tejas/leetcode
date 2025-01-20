class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<pair<int, int>> lookup(m * n + 1);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                lookup[mat[i][j]] = {i, j};
            }
        }
        vector<int> rows(m, 0);
        vector<int> cols(n, 0);
        for (int i = 0; i < arr.size(); i++) {
            int j = lookup[arr[i]].first;
            int k = lookup[arr[i]].second;
            rows[j]++;
            cols[k]++;
            if (rows[j] == n || cols[k] == m) {
                return i;
            }
        }
        return -1;
    }
};