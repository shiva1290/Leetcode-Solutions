class Solution {
public:
    double POWfunc(double x, long long y){
        if(y==1){
            return x;
        }
        if(y==0){
            return 1.0;
        }
        double half=POWfunc(x,y/2);
        if(y%2==0){
            return half*half;
        }
        return x * half * half;
    }
    double myPow(double x, int n) {
        long long N=n;
        if(n<0){
            return POWfunc(1/x,-N);
        }
        double val=POWfunc(x,N);
        return val;
    }
};