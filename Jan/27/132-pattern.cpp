class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int a = INT_MIN;

        for (int i = n-1; i>=0; i--){

            if (nums[i] < a){
                return true;
            }

            while (!st.empty() && nums[i] > st.top()){
                a = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};
