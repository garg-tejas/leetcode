class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        for (auto& edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        unordered_map<int, unordered_set<int>> mp;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto& ngbr : adj[node]) {
                mp[ngbr].insert(node);
                for (auto& preReq : mp[node])
                    mp[ngbr].insert(preReq);
                indegree[ngbr]--;
                if (indegree[ngbr] == 0)
                    q.push(ngbr);
            }
        }
        vector<bool> result(queries.size(), false);
        for (int i = 0; i < queries.size(); i++) {
            int src = queries[i][0];
            int des = queries[i][1];
            result[i] = mp[des].contains(src);
        }
        return result;
    }
};