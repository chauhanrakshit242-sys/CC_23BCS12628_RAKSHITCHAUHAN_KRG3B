class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> mp;

        int i = 0;
        int sum = 0;
        int maxi = 0;

        for(int j = 0; j < nums.size(); j++)
        {
            while(mp.find(nums[j]) != mp.end())
            {
                sum -= nums[i];
                mp.erase(nums[i]);
                i++;
            }

            mp[nums[j]]++;
            sum += nums[j];

            maxi = max(maxi, sum);
        }

        return maxi;
    }
};