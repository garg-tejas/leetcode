class Solution {
public:
    vector<vector<int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxFish = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                queue<pair<int, int>> q;
                if (grid[i][j]>0) {
                    q.push({i, j});
                    int fishCount=0;
                    while (!q.empty()) {
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();
                        fishCount += grid[row][col];
                        grid[row][col] = 0;
                        for (auto& dir : directions) {
                            int i_ = dir[0] + row;
                            int j_ = dir[1] + col;
                            if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n &&
                                grid[i_][j_]) {
                                fishCount += grid[i_][j_];
                                grid[i_][j_] = 0;
                                q.push({i_, j_});
                            }
                        }
                    }
                    maxFish=max(maxFish, fishCount);
                }
            }
        }
        return maxFish;
    }
};