class Solution {
public:
    int n;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int bfs(vector<vector<int>>& grid, int i, int j, int id) {
        int size = 0;
        queue<pair<int, int>> q;
        grid[i][j] = id;
        q.push({i, j});
        while (!q.empty()) {
            auto curr = q.front();
            size++;
            q.pop();
            int u = curr.first;
            int v = curr.second;
            for (auto& dir : directions) {
                int i_ = u + dir[0];
                int j_ = v + dir[1];
                if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < n &&
                    grid[i_][j_] == 1) {
                    grid[i_][j_] = id;
                    q.push({i_, j_});
                }
            }
        }
        return size;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int id = 2;
        n = grid.size();
        int maxSize = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int size = bfs(grid, i, j, id);
                    mp[id] = size;
                    id++;
                    maxSize = max(maxSize, size);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> st;
                    for (auto& dir : directions) {
                        int x = i + dir[0];
                        int y = j + dir[1];
                        if (x >= 0 && y >= 0 && x < n && y < n && grid[x][y]) {
                            st.insert(grid[x][y]);
                        }
                    }
                    int sum = 1;
                    for (auto& s : st) {
                        sum += mp[s];
                    }
                    maxSize = max(maxSize, sum);
                }
            }
        }
        return maxSize;
    }
};