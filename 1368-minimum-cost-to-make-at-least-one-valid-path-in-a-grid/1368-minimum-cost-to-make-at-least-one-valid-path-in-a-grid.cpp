class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        pq.push({0, 0, 0});
        result[0][0] = 0;
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int currCost = curr[0], i = curr[1], j = curr[2];
            if (result[i][j] < currCost)
                continue;
            for(int x = 0; x < 4; x++) {
                int I = i + dir[x][0];
                int J = j + dir[x][1];
                if (I >= 0 && I < m && J >= 0 && J < n) {
                    int gridDir = grid[i][j];
                    int dirCost = ((gridDir - 1 != x) ? 1 : 0);
                    int nCost = currCost + dirCost;
                    if (nCost < result[I][J]) {
                        result[I][J] = nCost;
                        pq.push({nCost, I, J});
                    }
                }
            }
        }
        return result[m - 1][n - 1];
    }
};