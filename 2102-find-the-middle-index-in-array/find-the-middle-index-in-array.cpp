class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int  sum =0;
        for(int i =0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        int left_sum=0;
        for(int  i =0; i<nums.size();i++)
        {
            sum = sum - nums[i];
            if(sum==left_sum)
            {
                return i;
            }
            left_sum =left_sum+nums[i];
        }
        return -1;
    }
};