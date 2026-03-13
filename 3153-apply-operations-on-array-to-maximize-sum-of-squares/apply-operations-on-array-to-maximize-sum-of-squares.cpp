class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        vector<int> bitCount(32, 0);

        for(int num : nums){
            for(int b = 0; b < 32; b++){
                if(num & (1 << b))
                    bitCount[b]++;
            }
        }

        long long ans = 0;

        for(int i = 0; i < k; i++){
            long long current = 0;

            for(int b = 0; b < 32; b++){
                if(bitCount[b] > 0){
                    current |= (1LL << b);
                    bitCount[b]--;
                }
            }

            ans = (ans + current * current) % MOD;
        }

        return ans;
    }
};