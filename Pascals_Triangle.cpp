//Solution:  TC- O(n*(2n-1))   SC- O(n*(2n-1))
vector<vector<int>> generate(int n) 
    {
        vector<vector<int>> res;
        res.push_back(vector<int>(1,1));

        while(n>1)
        {
            vector<int> A = res.back();
            vector<int> B;
            for(int i=0;i<A.size();i++)
            {
                if(i-1<0)
                    B.push_back(0+A[i]);
                else
                    B.push_back(A[i-1]+A[i]);
            }
            B.push_back(1);

            res.push_back(B);
            n--;
        }

        return res;    
    }
