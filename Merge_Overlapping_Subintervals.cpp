//Solution :-  TC: O(n*logn) + O(n)    SC: O(1)

vector<vector<int>> merge(vector<vector<int>>& A) 
    {
        sort(A.begin(),A.end());

        int a=A[0][0],b=A[0][1];
        vector<vector<int>> ans;
        for(int i=1;i<A.size();i++)
        {
            if(b>=A[i][0])
            {
                if(A[i][1]>=b)
                    b=A[i][1];
            }
            else
            {
                ans.push_back({a,b});
                a=A[i][0];b=A[i][1];
            }
        }    
        ans.push_back({a,b});
        return ans;
    }
