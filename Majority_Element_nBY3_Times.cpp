//solution   TC: O(n)   SC: O(1)  
vector<int> majorityElement(vector<int>& A) 
    {   
        if(A.size()<2)
            return A;

        int el1=A[0], cnt1=0;
        int el2=2147483646, cnt2=0;
        for(int i=0;i<A.size();i++)
        {    
            if(el1!=A[i])
            {
                el2=A[i];break;
            }
        }

        vector<int> ans;

        if(el2==2147483646)
        {
            ans.push_back(el1);
            return ans;
        }

        for(int i=0;i<A.size();i++)
        {
            if(cnt1==0 && A[i]!=el2)
            {
                el1=A[i];cnt1++;
            }
            else if(cnt2==0 && A[i]!=el1)
            {
                el2=A[i];cnt2++;
            }
            else if(A[i]==el1)
                cnt1++;
            else if(A[i]==el2)
                cnt2++;
            else
            {
                cnt1--;cnt2--;
            }
        }
        cout<<el1<<" "<<el2<<endl;
        cnt1=0;cnt2=0;
        for(int i=0;i<A.size();i++)
        {
            if(A[i]==el1)
                cnt1++;
            if(A[i]==el2)
                cnt2++;
        }
        if(cnt1>(A.size()/3))
            ans.push_back(el1);
        if(cnt2>(A.size()/3))
            ans.push_back(el2);
        
        return ans;
    }
   
