//solution: Recursion    TC: O(n)
void solve(vector<int>& A, int i,int sum, vector<int>& ans)
    {
        if(i>=A.size())
        {
            ans.push_back(sum);
            return ;
        }
        
        //Non pick
        solve(A,i+1, sum , ans);
        
        //pick
        solve(A, i+1, sum + A[i], ans);
    }
    
    vector<int> subsetSums(vector<int> A, int n)
    {
        vector<int> ans;
        solve(A,0,0,ans);
        return ans;
    }
