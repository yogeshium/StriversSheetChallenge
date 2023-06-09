//Solution: TC- O(n) SC- O(1)

void sortColors(vector<int>& nums) 
    {
        int a=0,b=0, c=nums.size()-1;
        while(a<=c)
        {
            if(nums[a]==0)
            {
                swap(nums[a],nums[b]);
                a++,b++;
            }
            else if(nums[a]==1)
            {
                a++;
            }
            else
            {
                swap(nums[a],nums[c]);
            }

            if(nums[c]==2)
                c--;
        }    
    }
