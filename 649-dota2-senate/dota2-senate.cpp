class Solution {
public:
    string predictPartyVictory(string senate) {

        queue<char> q;
        int countR = 0, countD = 0;

        for(char ch : senate)
        {
            q.push(ch);

            if(ch == 'R')
                countR++;
            else
                countD++;
        }

        int br = 0;
        int bd = 0; 

        while(countR > 0 && countD > 0)
        {
            char ch = q.front();
            q.pop();

            if(ch == 'R')
            {
                if(br > 0)
                {
                    br--;
                    countR--;
                }
                else
                {
                    bd++;
                    q.push(ch);
                }
            }
            else
            {
                if(bd > 0)
                {
                    bd--;
                    countD--;
                }
                else
                {
                    br++;
                    q.push(ch);
                }
            }
        }

        return countR > 0 ? "Radiant" : "Dire";
    }
};