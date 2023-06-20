//Solution 

//Recursion :   (TLE)
int solve(int i, int j, int& m, int& n)
    {
        if(i<0 || j<0 || i>=m || j>=n)
            return 0;
        if(i==m-1 && j==n-1)
            return 1;
        
        int bottom = solve(i+1,j,m,n);
        int right = solve(i,j+1,m,n);

        return bottom + right;
    }

    int uniquePaths(int m, int n) 
    {
        return solve(0,0,m,n);
    }


//DP Solution : I don't know. 

//Maths: (Combinators)
int uniquePaths(int m, int n) 
    {
        if(m==1 || n==1)
            return 1;
        m--;n--;
        if(m<n)
        {
            int temp = m;
            m=n;
            n=temp;
        }
        long long res=1;
        int j=1;
        for(int i=m+1;i<=m+n;i++,j++)
        {
            res *= i;
            res/=j;
        }

        return (int)res;
    }
