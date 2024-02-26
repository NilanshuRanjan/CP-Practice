#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; 
    cin >> t;
    while (t--){
        int n, k, x, sum = 0;
        cin >> n >> k >> x;
        vector<int> vec;
        for (int i = 0; i<n; i++){
            int a;
            cin >> a;
            vec.push_back(a);
            sum += a;
        }
        sort(vec.begin(), vec.end(), greater<int>());
        for (int j = 0; j<x; j++){
            sum -= 2*vec[j];
            vec[j] *= -1;
        }
        int ans = sum;
        for (int i = 0; i<k; i++){
            if (x < n){
                sum += abs(vec[i]) - 2*vec[x++];    
            }
            else sum += abs(vec[i]);
            ans = max(ans, sum);
        }

        cout << ans << endl;
    }
}
