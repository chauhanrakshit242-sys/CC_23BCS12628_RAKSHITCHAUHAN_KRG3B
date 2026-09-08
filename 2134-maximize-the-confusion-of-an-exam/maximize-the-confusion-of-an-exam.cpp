class Solution {
public:

    int solve(string s, int k, char target)
    {
        int left = 0;
        int count = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++)
        {
            // Character that needs to be changed
            if (s[right] != target)
                count++;

            // More than k changes required
            while (count > k)
            {
                if (s[left] != target)
                    count--;

                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }

    int maxConsecutiveAnswers(string answerKey, int k)
    {
        return max(
            solve(answerKey, k, 'T'),
            solve(answerKey, k, 'F')
        );
    }
};