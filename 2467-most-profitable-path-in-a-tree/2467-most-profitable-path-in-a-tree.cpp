class Solution {
public:
    bool DFS(int src, int prev, int time,
             unordered_map<int, vector<int>>& adjList,
             unordered_map<int, int>& bobTime) {
        if (src == 0) {
            bobTime[src] = time;
            return true;
        }
        for (auto& nei : adjList[src]) {
            if (nei == prev) continue;
            if (DFS(nei, src, time + 1, adjList, bobTime)) {
                bobTime[src] = time;
                return true;
            }
        }
        return false;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob,
                           vector<int>& amount) {
        unordered_map<int, vector<int>> adjList;
        for (auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        unordered_map<int, int> bobTime;
        DFS(bob, -1, 0, adjList, bobTime);
        int res = INT_MIN;
        queue<vector<int>> q; // node, time, parent, total profit till node
        q.push({0, 0, -1, amount[0]});
        while (!q.empty()) {
            vector<int> top = q.front();
            q.pop();
            int src = top[0], time = top[1], parent = top[2], profit = top[3];
            for (auto& nei : adjList[src]) {
                if (nei == parent) continue;
                int neiProfit = amount[nei];
                int neiTime = time + 1;
                if (bobTime.count(nei)) {
                    if (bobTime[nei] == neiTime) neiProfit /= 2;
                    else if (bobTime[nei] < neiTime) neiProfit = 0;
                }
                q.push({nei, neiTime, src, neiProfit + profit});
                if (adjList[nei].size() == 1) res = max(res, neiProfit + profit);
            }
        }
        return res;
    }
};