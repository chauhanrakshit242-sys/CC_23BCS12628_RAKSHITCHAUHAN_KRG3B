class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>mp;
        int j=0;
        int maxi =0;
        for(int i =0;i<n;i++)
        {   
            mp[nums[i]]++;
            while(mp[nums[i]] > k)
            {
                mp[nums[j]]--;
                j++;
            }
            maxi = max(maxi , i -j +1);
        }
        return maxi;
    }
};