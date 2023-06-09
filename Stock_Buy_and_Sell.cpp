//Solution: 

int maxProfit(vector<int>& A) 
    {
        int mx=A.back(), res=0;
        for(int i=A.size()-1;i>=0;i--)
        {
            if(mx-A[i]>res)
                res=mx-A[i];
            if(A[i]>mx)
                mx=A[i];
        }

        return res;
    }
