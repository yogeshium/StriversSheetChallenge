//Solution: TC: O(n) , SC: O(1)   
/* */
int maxSubArray(vector<int>& nums) 
    {
        int mx_curr=0, mx_so_far=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(mx_curr+nums[i]>mx_so_far)
                mx_so_far=mx_curr+nums[i];
            if(mx_curr+nums[i]<0)
                mx_curr=0;
            else
                mx_curr+= nums[i];
        } 
        return mx_so_far;
    }

//Not My Solution:
/*
 Divide-and-Conquer:
The Divide-and-Conquer algorithm breaks nums into two halves and find the maximum subarray sum in them recursively. 
Well, the most tricky part is to handle the case that the maximum subarray spans the two halves. For this case, 
we use a linear algorithm: starting from the middle element and move to both ends (left and right ends), record
the maximum sum we have seen. In this case, the maximum sum is finally equal to the middle element plus the maximum 
sum of moving leftwards and the maximum sum of moving rightwards.



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, nums.size() - 1);
    }
private:
    int maxSubArray(vector<int>& nums, int l, int r) {
        if (l > r) {
            return INT_MIN;
        }
        int m = l + (r - l) / 2, ml = 0, mr = 0;
        int lmax = maxSubArray(nums, l, m - 1);
        int rmax = maxSubArray(nums, m + 1, r);
        for (int i = m - 1, sum = 0; i >= l; i--) {
            sum += nums[i];
            ml = max(sum, ml);
        }
        for (int i = m + 1, sum = 0; i <= r; i++) {
            sum += nums[i];
            mr = max(sum, mr);
        }
        return max(max(lmax, rmax), ml + mr + nums[m]);
    }
};
*/
