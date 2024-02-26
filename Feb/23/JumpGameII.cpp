class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0, n = nums.size(), pos = 0;
        vector<int> jumpmax;
        jumpmax.push_back(nums[0]);

        for (int i = 1; i<n; i++){
            jumpmax.push_back(max(nums[i]+i, jumpmax[i-1]));
        }

        while (pos < n-1){
            ans ++;
            pos = jumpmax[pos];
        }

        return ans;
    }
};
