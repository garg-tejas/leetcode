class Solution {
public:
    bool isHappy(int n) {
        if(n==1 || num==7) return true;
        else if(n/10==0) return false;
        else{
            int num=0;
            while(n){
                num+=pow(n%10, 2);
                n/=10;
            }
            return isHappy(num);
        }
    }
};