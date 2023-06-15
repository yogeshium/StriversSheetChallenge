//Solution : (Recursive) -> TC: O(log n)  SC: O(log n)

double solve(double x, int n)
    {
        if(n==0)
            return 1;
        if(n==1)
            return x;

        double res = solve(x,n/2);
        if(n&1)
            return res*res*x;
        return res*res;
    }
    double myPow(double x, int n) 
    {
        if(n>=0)
            return solve(x,n);
        return 1.0/solve(x,abs(n));  
    }

//(Iterative)

double solve(double x, int n)
    {
        if(n==0)
            return 1;

        double res = 1;
        while(n)
        {
            if(n&1)
                res = res*x;
            x=x*x;
            n=n/2;
        }
        return res;
    }
    double myPow(double x, int n) 
    {
        if(n>=0)
            return solve(x,n);
        return 1.0/solve(x,abs(n));  
    }
