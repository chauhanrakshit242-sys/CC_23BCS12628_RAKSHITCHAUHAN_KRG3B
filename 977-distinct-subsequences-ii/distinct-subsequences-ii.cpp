class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;

        vector<long long> last(26, 0);

        long long dp = 1;

        for (char c : s) {
            long long old = dp;

            dp = (2 * dp % MOD - last[c - 'a'] + MOD) % MOD;

            last[c - 'a'] = old;
        }

        return (dp - 1 + MOD) % MOD;
    }
};