class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
         vector<vector<int>> arr(n,vector<int>(n, 0));

        int i = 0, j = 0, ele = 1;

        while (ele <= n*n){
            j = i;
            while (j < n-i){
                arr[i][j++] = ele++;
            }

            j = i + 1;
            while (j < n-i){
                arr[j++][n-i-1] = ele++;
            }

            j = n-i-2;
            while (j > i){
                arr[n-i-1][j--] = ele ++;
            }
            j = n - i - 1;
            while (j > i){
                arr[j--][i] = ele ++;
            }
            i++;
        }

        return arr;
    }
};
