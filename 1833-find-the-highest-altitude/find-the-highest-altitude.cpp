class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi=0;
        int curr_sum=0;
        for(int i=0;i<gain.size();i++)
        {
            curr_sum = curr_sum + gain[i];
            maxi = max(curr_sum,maxi);
        }
        return maxi;
    }
};