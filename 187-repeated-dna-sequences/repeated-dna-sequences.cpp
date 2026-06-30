class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        if(s.length() < 10) return {};

        set<int> seen;
        set<string> result;

        map<char, int> mp;
        mp.insert({'A', 0});
        mp.insert({'C', 1});
        mp.insert({'G', 2});
        mp.insert({'T', 3});

        int rep = 0;
        int k = 10;

        for(int i = 0; i < k; i++)
        {
            rep = rep + (int)pow(4, k - i - 1) * mp[s[i]];
        }

        seen.insert(rep);

        for(int i = k; i < s.length(); i++)
        {
            rep = rep - (int)pow(4, k - 1) * mp[s[i - k]];
            rep = rep * 4;
            rep = rep + mp[s[i]];

            if(seen.find(rep) != seen.end())
            {
                result.insert(s.substr(i - k + 1, k));
            }

            seen.insert(rep);
        }

        return vector<string>(result.begin(), result.end());
    }
};