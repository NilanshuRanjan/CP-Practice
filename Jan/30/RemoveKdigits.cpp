class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        stack<char> ans;
        ans.push(num[0]);
        if (k == n){
            return "0";
        }
        for (int i = 1; i<n; i++){
            // int a = k + ans.size() - i;
            while (!ans.empty() && ans.top() > num[i] && k>0){
                ans.pop();
                --k;
            }
            ans.push(num[i]);

            if(ans.size() == 1 && num[i] == '0')
                ans.pop();
        }

         while(k && !ans.empty())
        {
            --k;
            ans.pop();
        }

        string res;
        bool valid = false;
        while(!ans.empty())
        {
            res.push_back(ans.top());
            ans.pop();
        }
        
        reverse(res.begin(),res.end());

        if(res.length() == 0)
            return "0";

        return res;
    }
};
