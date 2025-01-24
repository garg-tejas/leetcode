class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            for (int& v : graph[i]) {
                adj[v].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        vector<bool> isSafe(n, false);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            isSafe[curr] = true;
            for (int& v : adj[curr]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
        }
        vector<int> safe;
        for (int i = 0; i < n; i++) {
            if (isSafe[i])
                safe.push_back(i);
        }
        return safe;
    }
};