class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0, n = s.length();
        char a, b;
        string k;
        if (x > y){
            a = 'a';
        }
        else{
            a = 'b';
        }

        if (a == 'a'){
            b = 'b';
        }
        else{
            b = 'a';
        }

        for (int i = 0; i<n; i++){
            if ( !k.empty() && k.back() == a && s[i] == b){
                k.pop_back();
                ans += max(x, y);
            }
            else{
                k.push_back(s[i]);
            }
        }

        s = k;
        k.clear();
        n = s.length();

        for (int i = 0; i<n; i++){
            if ( !k.empty() && k.back() == b && s[i] == a){
                ans += min(x, y);
                k.pop_back();
            }
            else{
                k.push_back(s[i]);
            }
        }

        return ans;

    }
};
