class Solution {
public:
    string getCode(const string& s) {
        vector<int> count(26, 0);

        for (char ch : s)
            count[ch - 'a']++;

        string key;
        for (int i = 0; i < 26; i++) {
            key += "#";
            key += to_string(count[i]);
        }

        return key;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (const string& str : strs) {
            string key = getCode(str);
            mp[key].push_back(str);
        }

        vector<vector<string>> ans;

        for (auto& it : mp)
            ans.push_back(it.second);

        return ans;
    }
};