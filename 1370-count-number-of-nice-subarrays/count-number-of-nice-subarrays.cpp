class Solution {
public:
    int atmost(vector<int>& nums, int k)
    {
        int i=0;
        int odd=0;
        int count=0;
        for(int j =0;j<nums.size();j++)
        {
           odd+=nums[j]%2;
           while(odd>k)
           {
             odd = odd-(nums[i]%2);
             i++;
           }
           count = count + (j - i + 1);
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        if(nums.size()<k)return 0;
        return atmost(nums,k)-atmost(nums,k-1);
    }
};