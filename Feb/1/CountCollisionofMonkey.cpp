class Solution {
public:
    int M = 1e9 + 7;
    int solve(long long int a, int n){
        a %= M;
        int ans = 1;
        while (n > 0){
            if (n&1){
                ans = (a*ans)%M;
            }
            a = (a*a)%M;
            n = n>>1;
        }
        return ans;
    }
    int monkeyMove(int n) {
        return (solve(2, n) + M - 2)%M;
    }
};
