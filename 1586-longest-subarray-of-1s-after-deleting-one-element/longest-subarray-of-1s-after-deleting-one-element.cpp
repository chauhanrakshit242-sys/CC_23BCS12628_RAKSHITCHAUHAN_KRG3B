class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int countzero=0;
        int i=0;
        int maxi=0;
        for(int j =0;j<n;j++)
        {
            if(nums[j]==0)
            {
                 countzero++;
            }
            while(countzero > 1)
            {
                if(nums[i]==0)
                {
                    countzero--;
                }
                i++;
            }
            maxi = max(maxi, j-i+1);
        }
        return maxi-1;
    }
};