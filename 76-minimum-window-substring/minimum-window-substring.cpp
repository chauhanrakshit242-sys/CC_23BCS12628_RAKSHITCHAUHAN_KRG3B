class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();

        if (t.length() > n) {
            return "";
        }

        unordered_map<char, int> mp;

        for (char ch : t) {
            mp[ch]++;
        }

        int i = 0;
        int count = 0;
        int minLen = INT_MAX;
        int start = 0;

        for (int j = 0; j < n; j++) {

            // Add s[j]
            if (mp.find(s[j]) != mp.end()) {
                mp[s[j]]--;

                if (mp[s[j]] >= 0) {
                    count++;
                }
            }

            // Valid window
            while (count == t.length()) {

                // Update minimum window
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    start = i;
                }

                // Remove s[i]
                if (mp.find(s[i]) != mp.end()) {
                    mp[s[i]]++;

                    if (mp[s[i]] > 0) {
                        count--;
                    }
                }

                i++;
            }
        }

        if (minLen == INT_MAX) {
            return "";
        }

        return s.substr(start, minLen);
    }
};