//Solution :  Recursion
void solve(vector<int>& A, int i, vector<int>curr, vector<vector<int>>& ans)
    {
        while(i<A.size())
        {
            curr.push_back(A[i]);
            ans.push_back(curr);
            
            //Pick
            solve(A,i+1,curr,ans);
            
            int k=i+1;
            while(k<A.size() && A[k]==A[i])
                k++;
            i=k;
            
            //Non Pick
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        vector<int> curr;
        ans.push_back(curr);
        
        solve(nums,0, curr, ans);

        return ans;    
    }
