class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> result(n);
        unordered_map<int, int> color, colorBall;
        int idx = 0;
        for (auto& query : queries) {
            int c = query[1], b = query[0];
            color[c]++;
            if (colorBall.find(b) != colorBall.end()){
                color[colorBall[b]]--;
            if(color[colorBall[b]] == 0) {
                color.erase(colorBall[b]);
            }}
            colorBall[b] = c;
            result[idx] = color.size();
            idx++;
        }
        return result;
    }
};