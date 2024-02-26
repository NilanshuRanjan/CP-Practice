#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int arr[n];

        for (int i = 0; i<n; i++){
            cin >> arr[i];
        }

        int max_diff = 0;
        for (int j = 0; j<n-1; j++){
            if (arr[j] > arr[j+1]){
                max_diff = max(max_diff, arr[j] - arr[j+1]);
                arr[j+1] = arr[j];
            }
        }
        if (max_diff == 0) cout << 0 << endl;
        else cout << ceil(log2(max_diff+1)) << endl;
    }
}
