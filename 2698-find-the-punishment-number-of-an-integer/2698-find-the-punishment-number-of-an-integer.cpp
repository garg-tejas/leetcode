class Solution {
public:
    int punishment[1001];
    int check(int num, int curSum, int target) {
        if (num == 0)
            return curSum == target;
        return check(num / 10, curSum + num % 10, target) ||
               check(num / 100, curSum + num % 100, target) ||
               check(num / 1000, curSum + num % 1000, target) ||
               check(num / 10000, curSum + num % 10000, target);
    }
    void preCompute(){
        for(int num=1;num<1001;num++){
            if(check(num*num,0,num)){
                punishment[num]=num*num;
            }
            else{
                punishment[num]=0;
            }
        }
        for(int i=1;i<1001;i++){
            punishment[i]+=punishment[i-1];
        }
    }
    int punishmentNumber(int n) {
        preCompute();
        return punishment[n];
    }
};