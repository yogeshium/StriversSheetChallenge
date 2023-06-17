//Solution :   TC - O(n)   SC - O(1)
int majorityElement(vector<int>& A) 
    {
        int ans=A[0], cnt=1;
        for(int i=1;i<A.size();i++)
        {
            if(cnt==0)
            {
                cnt++; ans=A[i];
            }
            else if(ans==A[i])
                cnt++;
            else
                cnt--;
        }
        return ans;
    }
