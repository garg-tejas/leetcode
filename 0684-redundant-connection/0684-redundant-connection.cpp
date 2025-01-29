class Solution {
public:
    int n;
    bool bfs(map<int, vector<int>>& mp, int u, int v) {
        vector<bool> visited(n + 1, false);
        queue<int> q;
        q.push(u);
        while (!q.empty()) {
            int curr = q.front();
            visited[curr] = true;
            q.pop();
            if (curr == v)
                return true;
            for (auto& node : mp[curr]) {
                if (!visited[node])
                    q.push(node);
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        map<int, vector<int>> mp;
        n = edges.size();
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (mp.find(u) != mp.end() && mp.find(v) != mp.end() &&
                bfs(mp, u, v))
                return edge;
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        return {};
    }
};