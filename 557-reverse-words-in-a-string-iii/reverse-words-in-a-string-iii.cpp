class Solution {
public:
    void reverse(string & str  , int i , int r)
    {
        while(i<r)
        {
            char temp = str[i];
            str[i]=str[r];
            str[r]=temp;
            i++;
            r--;
        }
    }
    string reverseWords(string s) {
       int start=0;
       int high =0;
       while(high<=s.length())
       {
           if(high==s.length()||s[high]==' ')
           {
              reverse(s , start , high -1);
              start=high+1;
           }
           high++;
       } 
       return s;
    }
};