class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n =nums.size();
        unordered_map<int,int>count;
        long long sum=0;
        long long  maxi=INT_MIN;
        for(int i=0;i<k;i++)
        {
            sum = sum + nums[i];
            count[nums[i]]++;
        }
        if(count.size()==k)
        {
            maxi =sum;
        }
        int i=0;
        int j=k;
        while(j< n)
        {
            sum  = sum + nums[j];
            count[nums[j]]++;
            sum =sum -nums[i];
            count[nums[i]]--;
            if(count[nums[i]]==0)
            {
                count.erase(nums[i]);
            }
            if(count.size()==k)
            {
              maxi =max(sum,maxi);
            }
            j++;
            i++;
        }
        if(maxi==INT_MIN)
        {
            return 0;
        }
        return maxi;
    }
};