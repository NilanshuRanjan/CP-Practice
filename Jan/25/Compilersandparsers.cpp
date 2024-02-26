#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    
    while (t--){
        string s;
        cin >> s;
        int n = s.length(), ans = 0;
        stack<char> st;
        
        for (int i = 0; i<n; i++){
            if (st.empty()){
                st.push(s[i]);
            }
            else if (st.top() == s[i]){
                st.push(s[i]);
            }
            else if (s[i] == '<'){
                st.push(s[i]);
            }
            else if (s[i] == '>'){
                st.pop();
            }
            
            if (st.empty()){
                ans = i + 1;
            }
        }
        cout << ans << endl;
    }
}
