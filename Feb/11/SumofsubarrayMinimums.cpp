class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<pair<int, int>> st_left;
        stack<pair<int, int>> st_right;
        long long int left[arr.size()], right[arr.size()];
        for (int i = 0; i<arr.size(); i++){
            int count = 1;
            while (!st_left.empty() && st_left.top().first > arr[i]){
                count += st_left.top().second;
                st_left.pop();
            }
            st_left.push(make_pair(arr[i], count));
            left[i] = count;
        }

        for (int j = arr.size()-1; j>=0; j--){
            long long int count = 1;
            while (!st_right.empty() && st_right.top().first >= arr[j]){
                count += st_right.top().second;
                st_right.pop();
            }
            st_right.push(make_pair(arr[j], count));
            right[j] = count;
        }

        long long int ans = 0, MOD = 1000000007;
        for (int k = 0; k<arr.size(); k++){
            ans = (ans + left[k]*right[k]*arr[k]) % MOD;
        }

        return ans;
    }
};
