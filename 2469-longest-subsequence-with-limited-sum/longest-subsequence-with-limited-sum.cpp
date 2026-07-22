class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n =nums.size();
        sort(nums.begin(),nums.end());
        vector<int>prefix(n);
        prefix[0]=nums[0];
        for(int i= 1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+nums[i];
        }
        vector<int>ans(queries.size());
        for(int i =0;i<queries.size();i++)
        {   int  left =0;
            int right =n-1;
            int res=0;
            while(left<=right)
            {
                int mid = left + (right-left)/2;
                if(prefix[mid]<=queries[i])
                {
                    res=mid+1;
                    left=mid+1;
                }
                else
                {
                    right =mid-1;
                }
            }
            ans[i]=res;
        }
        return ans;
    }
};