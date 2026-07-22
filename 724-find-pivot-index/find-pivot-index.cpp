class Solution {
public:
    int pivotIndex(vector<int>& nums) {
       int n = nums.size();
       int tot=0;
       for(int i=0;i<n;i++)
       {
        tot+=nums[i];
       } 
       int left_sum=0;
       for(int i =0;i<n;i++)
       {
          tot= tot-nums[i];
          if(left_sum==tot)
          {
            return i;
          }
          left_sum+=nums[i];
       }
       return -1;
    }
};