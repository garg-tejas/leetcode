class Solution {
public:
    typedef pair<int, pair<int, int>> PP;
    vector<vector<int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    int trapRainWater(vector<vector<int>>& heightMap) {
        int water = 0;
        int m = heightMap.size();
        int n = heightMap[0].size();
        priority_queue<PP, vector<PP>, greater<>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i : {0, m - 1}) {
            for (int j = 0; j < n; j++) {
                pq.push({heightMap[i][j], {i, j}});
                visited[i][j] = true;
            }
        }
        for (int i = 1; i < m - 1; i++) {
            for (int j : {0, n - 1}) {
                pq.push({heightMap[i][j], {i, j}});
                visited[i][j] = true;
            }
        }
        while (!pq.empty()) {
            PP curr = pq.top();
            pq.pop();
            int height = curr.first;
            int i = curr.second.first;
            int j = curr.second.second;

            for (auto& dir : directions) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];
                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n &&
                    !visited[i_][j_]) {
                    water += max(height-heightMap[i_][j_],0);
                    pq.push({max(height, heightMap[i_][j_]), {i_, j_}});
                    visited[i_][j_] = true;
                }
            }
        }
        return water;
    }
};