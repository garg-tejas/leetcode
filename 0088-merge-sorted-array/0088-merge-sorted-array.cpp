class Solution {
public:
    void merge(vector<int>& num1, int m, vector<int>& num2, int n) {
        int idx1=m-1, idx2=n-1, idx=m+n-1;
        while(idx1>=0 && idx2>=0){
            if(num1[idx1]>num2[idx2]){
                num1[idx]=num1[idx1];
                idx1--;
            }
            else{
                num1[idx]=num2[idx2];
                idx2--;
            }
            idx--;
        }
        while(idx2>=0){
            num1[idx--]=num2[idx2--];
        }
    }
};