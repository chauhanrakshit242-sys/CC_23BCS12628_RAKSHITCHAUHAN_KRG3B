class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n= s.length();
        map<char,int>map;
        int i =0;int j=0;
        int  maxi =0;
        while(j < n)
        {
              if(map.find(s[j])!=map.end())
              {
                 i = max(i,map[s[j]]+1);//  it increase the index by  last index old duplicate value it skip all the duplicate  value ,now i wil point that index  after that index  we have all the unique string  yet..
              }
              map[s[j]]=j;
              j++;
              maxi =max(maxi,j - i);
        }  
        return maxi; 
    }
};