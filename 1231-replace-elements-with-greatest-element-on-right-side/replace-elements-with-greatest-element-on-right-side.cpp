class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        if(arr.size()==1)
        return {-1};
        vector<int>suffix_max(n);
        suffix_max[n-1]=-1;
        for(int i = n-2 ;i>=0;i--)
        {
            suffix_max[i] = max(suffix_max[i+1],arr[i+1]);
        }
        return suffix_max;
    }
};