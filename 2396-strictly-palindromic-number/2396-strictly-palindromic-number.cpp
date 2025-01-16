class Solution {
public:
    bool nBasePalindrome(int num, int n){
        string baseN;
        while(num){
            baseN+=num%n;
            num/=n;
        }
        int left=0, right=baseN.length();
        while(left<right){
            if(baseN[left]!=baseN[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    bool isStrictlyPalindromic(int n) {
        for(int i=2;i<n-1;i++){
            bool flag=nBasePalindrome(n,i);
            if(!flag) return false;
        }
        return true;
    }
};