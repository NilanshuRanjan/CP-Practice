class Solution {
public:
    int trailingZeroes(int n){
        if (n < 5) return 0;
        int twos = 0, fives = 0;
        for (int i = n; i>0; i--){
            int x = i;
            while (x%5 == 0){
                x /= 5;
                fives++;
            }
        }
        return fives;
    }
};
