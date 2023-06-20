//solution :Merge Sort (Like in count inversion) -> TC - O(nlogn)   SC - O(1)


void merge(vector<int>& A, int s, int mid, int e, int& cnt)
    {
        int i=mid, j=e;
        while(i>=s && j>=mid+1)
        {
            if((long long)(A[i])>2*(long long)(A[j]))
            {
                cnt += j-mid;
                i--;
            }
            else
                j--;
        }

         int n1=mid-s+1, n2=e-mid;
         int g=n1+n2;
         g=(g/2) + (g%2);
         for(;g>0;g=(g/2) + (g%2))
         {
             int i=s;int j=s+g;
             while(j<=e)
             {
                 if(A[i]>A[j])
                 {
                    //swap
                    int temp = A[i];
                    A[i]=A[j];
                    A[j]=temp;
                 }
                 i++;j++;
             }
              if(g==1)
                break;
         }

    }

    void mergesort(vector<int>& A, int s, int e, int& ans)
    {
        if(s>=e)
            return ;
        int mid = s+(e-s)/2;
        mergesort(A,s,mid,ans);
        mergesort(A,mid+1,e,ans);

        merge(A,s,mid,e,ans);
    }

    int reversePairs(vector<int>& nums) 
    {
        int ans=0;
        mergesort(nums, 0, nums.size()-1, ans);
        return ans;
    }
