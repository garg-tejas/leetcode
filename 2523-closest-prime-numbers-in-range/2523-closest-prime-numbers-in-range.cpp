class Solution {
public:
    vector<int> seive(int limit) {
        vector<int> seive(limit + 1, 1);
        seive[0] = 0;
        seive[1] = 0;
        for (int i = 2; i * i <= limit; i++) {
            if (seive[i]) {
                for (int mul = i * i; mul <= limit; mul += i) {
                    seive[mul] = 0;
                }
            }
        }
        return seive;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> seiveArray = seive(right);
        vector<int> primeNum;
        for(int i=left;i<=right;i++){
            if(seiveArray[i]){
                primeNum.push_back(i);
            }
        }
        if(primeNum.size()<2){
            return {-1,-1};
        }
        int minDiff = INT_MAX;
        vector<int>closestPair (2,-1);
        for(int i=0;i<primeNum.size()-1;i++){
            int diff = primeNum[i+1] - primeNum[i];
            if(diff<minDiff){
                minDiff = diff;
                closestPair[0] = primeNum[i];
                closestPair[1] = primeNum[i+1];
            }
        }
        return closestPair;
    }
};