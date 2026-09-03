class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        long long prod =1;
        int count=0;
        for(int i =0 , j=0;j<n;j++)
        {
            prod*=nums[j];
            while(i<=j && prod >=k)
            {
                prod = prod/nums[i];
                i++;
            }
            count+=(j-i+1);
        }
        return count;
    }
};