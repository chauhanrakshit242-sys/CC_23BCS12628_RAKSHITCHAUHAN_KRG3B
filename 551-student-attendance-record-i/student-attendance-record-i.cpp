class Solution {
public:
    bool checkRecord(string s) {
        int countA=0;
        int countB=0;
        int countC=0;
        for(int i =0;i<s.length();i++)
        {
            if(s[i]=='A')
            {
            countA++;
            if(countA>=2)
            {
                return false;
            }
            countC=0;
            }
            if(s[i]=='P')
            {
            countB++;
            countC=0;
            }
            if(s[i]=='L')
            {
               countC++;
               if(countC >=3)
               {
                return false;
               }
            }
        }
        return true;
    }
};