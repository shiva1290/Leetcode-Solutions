class Solution {
public:
    int GCD(int a, int b) {
        if (a%b == 0) {
            return b;
        }
        return GCD(b, a % b);
    }

    int LCM(int a, int b) { return (a * b) / GCD(a, b); }

    int mirrorReflection(int p, int q) {
        int gcd=GCD(p,q);
        int lcm=LCM(p,q);
        int m=lcm/p;
        int n=lcm/q;
        if(m%2==0 && n%2!=0) return 0;
        if(m%2!=0 && n%2!=0) return 1;
        return 2;
    }
};