class Solution {
public:
    string getcode(string s)
    {
        int n = s.length();
        vector<int>count(26,0);
        for(char ch : s)
        {
            count[ch-'a']++;
        }
        string res="";

for (int i = 0; i < 26; i++)
{
    if (count[i] > 0)
    {
        res.push_back('a' + i);
        res += to_string(count[i]);
        res.push_back('#');
    }
}
        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(string str : strs)
        {
            string temp = getcode(str);
            mp[temp].push_back(str);
        }
        vector<vector<string>>ans;
        for(auto it : mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};