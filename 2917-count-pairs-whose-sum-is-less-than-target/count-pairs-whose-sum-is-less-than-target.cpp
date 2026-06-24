class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int cnt =0;
        int n =nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        int j=n-1;
        while(i<j)
        {
            if(nums[i]+nums[j] >= target)
            {
                j--;
            }else{
            cnt = cnt + j-i;
            i++;
            }
        }
        return cnt;
    }
};