#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        vector<int> vec1(m);
        for (int i = 0; i<m; i++){
            cin >> vec1[i];
        }
        sort(vec1.begin(), vec1.end());
        vector<int> popu(m);
        for (int i = 0; i<m-1; i++){
            popu.push_back(vec1[i+1] - vec1[i] - 1);
        }
        popu.push_back(vec1[0]-1 + n-vec1[m-1]);
        sort(popu.begin(), popu.end(), greater<int>());
        int tmr = 0, safe = 0;
        for (int i = 0; i < m; i++){
            int cur = popu[i];
            cur -= 2*tmr;
            if (cur <= 0) break;
            safe += cur-1;
            if (cur == 1) safe ++;
            tmr += 2;
        }
        cout << (n-safe) << endl;
    }
}
