class Solution{
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0;

        long long i = nums.size() - 2, a = nums[nums.size() - 1];
        while (i >= 0){
            if (nums[i] > a){
                long long div = ceil(double(nums[i])/double(a));
                ans += div-1;
                a = nums[i]/div;
            }
            else a = nums[i];
            i--;
        }
        return ans;
    }
};
