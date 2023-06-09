//My Solution (using two Pointer)
//TC: O(n)   SC: O(1)
 void nextPermutation(vector<int>& nums) 
    {
        int index=-1;
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                index=i;
                break;
            }
        }

        for(int i=nums.size()-1;i>=index && index!=-1;i--)
        {
            if(nums[i]>nums[index])
            {
                int n=nums[i];
                nums[i]=nums[index];
                nums[index]=n;

                break;
            }
        }

        int i=index+1, j=nums.size()-1;
        while(i<j)
        {
            int n=nums[i];
            nums[i]=nums[j];
            nums[j]=n;
            i++;j--;
        }
    }
