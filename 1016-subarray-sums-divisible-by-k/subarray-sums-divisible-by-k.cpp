class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        int prefix_sum = 0;
        int count = 0;

        mp[0] = 1;

        for (int i = 0; i < nums.size(); i++) {

            prefix_sum += nums[i];

            int rem = prefix_sum % k;
            rem = (rem + k) % k;   // normalize

            if (mp.find(rem) != mp.end()) {
                count += mp[rem];
            }

            mp[rem]++;
        }

        return count;
    }
};