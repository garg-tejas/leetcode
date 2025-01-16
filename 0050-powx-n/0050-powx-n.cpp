class Solution {
public:
    double myPow(double x, int n) {
        if(x==1){
            return x;
        }
        if(n==0){
            return 1;
        }
        double p = n;
        if(n<0){
            x=1/x;
            p*=-1;
        }
        if(n%2==0){
            return myPow(x*x,p/2);
        }
        else{
            return x*myPow(x,p-1);
        }

    }
};