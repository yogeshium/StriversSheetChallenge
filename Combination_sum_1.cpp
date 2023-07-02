//Solution: (Recursion) 
void solve(vector<int>& A, int i, int t,vector<int> curr, vector<vector<int>>& ans)
    {
        if(i>=A.size() || t<0) return ;
        if(t==0)
        {
            ans.push_back(curr);
            return ;
        }

        //pick
        curr.push_back(A[i]);
        solve(A,i,t-A[i],curr,ans);

        //nonpick
        curr.pop_back();
        solve(A,i+1,t,curr,ans);

    }


    vector<vector<int>> combinationSum(vector<int>& arr, int t) 
    {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(arr, 0, t,curr, ans);

        return ans;
    }
