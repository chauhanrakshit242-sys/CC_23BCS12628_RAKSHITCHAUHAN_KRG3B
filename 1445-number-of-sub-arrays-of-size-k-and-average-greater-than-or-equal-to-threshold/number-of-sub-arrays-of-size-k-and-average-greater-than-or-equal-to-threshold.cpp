class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
         int n =arr.size();
         int maxTarget = k *threshold;
         int sum =0;
         for(int i = 0 ;i<k;i++)
         {
            sum = sum +arr[i];
         }
         int i =0;
         int j =k;
         int count=0;
         while(j<n)
         {
            if(sum >= maxTarget)
            {
                count++;
            }
            sum = sum - arr[i]+arr[j];
            i++;
            j++;
         }
         if(sum >= maxTarget)
            {
                count++;
            }
         return  count;
    }
};