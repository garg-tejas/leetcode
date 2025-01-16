class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int count=0;
        for(int i=piles.size()/3;i<piles.size();i+=2){
            count+=piles[i];
        }
        return count;
    }
};