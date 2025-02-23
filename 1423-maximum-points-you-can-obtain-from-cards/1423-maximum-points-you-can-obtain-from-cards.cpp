class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lSum=0, rSum=0;
        for(int i=0;i<k;i++){
            lSum += cardPoints[i];
        }
        int maxPoint = lSum;
        int n = cardPoints.size();
        for(int i=n-1;i>=n-k;i--){
            rSum += cardPoints[i];
            lSum -= cardPoints[i-n+k];
            maxPoint = max(maxPoint, lSum+rSum);
        }
        return maxPoint;
    }
};