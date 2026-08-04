class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxi=INT_MIN;
        int mini=INT_MAX;
        set<int>st;
        for(int i=0;i<nums.size();i++)
        {
            st.insert(nums[i]);
            if(nums[i]>maxi)
            {
                maxi=nums[i];
            }
            if(nums[i]<mini)
            {
                mini=nums[i];
            }
        }
        vector<int>ans;
        for(int i=mini;i<=maxi;i++)
        {
            if(!st.count(i))
            {
                ans.push_back(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};