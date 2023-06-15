//Solution: (TC= O(nlogn)  SC: O(n))  

#include <bits/stdc++.h> 

void merge(long long*A, int s, int mid, int e,long long& cnt)
{
    int i=s, j=mid+1,k=0;
    long long* B = new long long[e-s+1];
    while(i<=mid && j<=e)
    {
        if(A[i]<A[j])
        {    
            B[k++]=A[i++];
            
        }
        else if(A[i]>A[j])
        {    
            cnt=cnt+(mid-i+1);
            B[k++] = A[j++];
        }
        else
        {
            B[k++] = A[i++];
            B[k++] = A[j++];
        }
    }
    while(i<=mid)
        B[k++]=A[i++];
    while(j<=e)
        B[k++]=A[j++];
    
    for(int i=s, j=0;i<=e;i++,j++)
        A[i]=B[j];


}

void mergesort(long long* A, int s, int e, long long& cnt)
{
    if(s>=e)
        return ;
    int mid = s+(e-s)/2;
    mergesort(A,s,mid,cnt);
    mergesort(A,mid+1,e,cnt);
    merge(A,s,mid,e,cnt);
}

long long getInversions(long long *arr, int n)
{
    long long cnt=0;
    mergesort(arr,0,n-1,cnt);
    return cnt;
}
