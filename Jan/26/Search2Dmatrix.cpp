class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low=0;
        int high=matrix.size();
        int row=0;
        while(low<high){
            int mid=(low+high)/2;
            if(low==mid||mid==high){
                row=low;
                break;
            }
            int n=matrix[mid][0];
            if(n<=target){
                low=mid;
            }else{
                high=mid;
            }
        }

        high=matrix[0].size();
        cout<<row;
        int ans=-1;

        int start = 0;
        int end =matrix[0].size()-1;              
     
    for (int i = 0; i<matrix[0].size() ;i++){
        int mid = (end - start)/2;
        if (matrix[row][i] == target)  {
            ans=i;
            break;
        }
        else if (matrix[row][mid] > target)  {
            end = mid - 1;
        }
        else    {
            start = mid + 1;
        }
    }
        if(ans==-1){
            return false;
        }
        return true;
    }
};
