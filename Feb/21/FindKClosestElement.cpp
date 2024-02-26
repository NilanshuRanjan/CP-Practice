class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        vector<pair<int, int>> vec; 
        for (int i = 0; i<arr.size(); i++){
            vec.push_back(make_pair(abs(x-arr[i]), arr[i]));
        }
        sort(vec.begin(), vec.end());
        for (auto i : vec){
            ans.push_back(i.second);
            if (ans.size() == k) break;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
