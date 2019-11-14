class Solution {
public:
    double myPow(double x, int n) {
        if (n==0) return 1;
        if (n==1) return x;

        long long N = n;
        if (n<0){
            x = 1/x;
            N = -N;
        }

        double ans = myPow(x, N>>1);
        ans *= ans;
        if (N & 0x1 == 1)
            ans *= x;
        
        return ans;
    }
};