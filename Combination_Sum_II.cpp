//Solution :   TC= O(2^n)  
void solve(vector<int>& A, int i, int t, vector<int> curr, vector<vector<int>>& ans)
    {
        if(t==0)
        {    
            ans.push_back(curr);
            return;
        }
        if(i>=A.size() || t<0)
            return ;
        
        
        int k=i+1;
        while(k<A.size() && A[k]==A[i])
            k++;
        
        //NonPick
            solve(A,k,t,curr,ans);
        //Pick
            curr.push_back(A[i]);
            solve(A,i+1,t-A[i],curr,ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& A, int t) 
    {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(A.begin(), A.end());

        solve(A,0,t,curr,ans);

        return ans;
    }
