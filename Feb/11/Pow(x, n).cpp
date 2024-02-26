class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        int a = abs(n);
        while (a > 0){
            if (a&1){
                res = res * x;
            }
            x = x * x;
            a = a >> 1;
        }
        if (n < 0) return 1/res ;
        return res;
    }
};
