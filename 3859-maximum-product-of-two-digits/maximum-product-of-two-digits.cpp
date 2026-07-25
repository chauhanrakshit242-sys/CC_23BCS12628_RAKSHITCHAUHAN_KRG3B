class Solution {
public:
    int maxProduct(int n) {
        int first=INT_MIN;
        int second=INT_MIN;
        while(n!=0)
        {
            int digit = n %10;
            if(digit>=first)
            {
                second=first;
                first=digit;
            }
            else if(second < digit)
            {
                second = digit;
            }
            n = n/10;
        }
        return first * second;
    }
};