//Solution :  (TC- O(logn)    SC- O(1) )

bool searchMatrix(vector<vector<int>>& mat, int t) 
    {
        int row =mat.size(), col = mat[0].size();
        int s=0, e=row*col -1;
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if(mat[mid/col][mid%col]==t)
                return true;
            else if(mat[mid/col][mid%col]>t)
                e=mid-1;
            else
                s=mid+1;
        }
        return false;
    }
