class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());
        int count=0;
        while(pq.top()<k){
            long long smallest = pq.top();
            pq.pop();
            long long smaller = pq.top();
            pq.pop();
            long long newElement = smallest*2LL + smaller;
            pq.push(newElement);
            count++;
        }
        return count;
    }
};