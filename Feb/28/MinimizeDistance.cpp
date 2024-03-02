#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;

    while (t--){
        long long int n, k;
        cin >> n >> k;
        vector<int> bag_pos;
        vector<int> bag_pos_2;

        for (int i = 0; i<n; i++){
            int a;
            cin >> a;
            if (a < 0) bag_pos_2.push_back(-a);
            else bag_pos.push_back(a);
        }

        sort(bag_pos.begin(), bag_pos.end());
        if (!bag_pos_2.empty()) sort(bag_pos_2.begin(), bag_pos_2.end());


        long long int ans = 0;
    
        for (int i = bag_pos.size()-1; i>=0; i-=k){
            ans += 2*bag_pos[i];
        }

        for (int i = bag_pos_2.size()-1; i>=0; i-=k){
            ans += 2*bag_pos_2[i];
        }
        // cout << ans << endl; 

        if (bag_pos.size() != 0 && bag_pos_2.size() != 0){
            ans -= max(bag_pos[bag_pos.size()-1], bag_pos_2[bag_pos_2.size()-1]);
        }
        else if (bag_pos_2.size() == 0){
            ans -= bag_pos[bag_pos.size()-1];
        }
        else if (bag_pos.size() == 0){
            ans -= bag_pos_2[bag_pos_2.size()-1];
        }

        cout << ans << endl;
    }
}
