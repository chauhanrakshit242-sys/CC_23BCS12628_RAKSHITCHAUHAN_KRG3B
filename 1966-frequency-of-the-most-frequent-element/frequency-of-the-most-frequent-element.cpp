class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int maxi = 0;
        long long sum =0;
        int i=0;
        int j=0;
        while(j<n)
        {
            sum = sum + nums[j];
            while((long long) nums[j] * (j-i+1) - sum  > k)
            {
                sum = sum - nums[i];
                i++;
            }
            maxi = max(maxi , j-i+1);
            j++;
        }
        return maxi;
    }
};