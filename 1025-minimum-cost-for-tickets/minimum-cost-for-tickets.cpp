class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int ans =0;
        queue<pair<int, int>>month;
        queue<pair<int, int>>weekly;
        for(int day : days)
        {
          while(!month.empty() && month.front().first + 30 <= day)
          month.pop();
          while(!weekly.empty() && weekly.front().first + 7 <= day)
          weekly.pop();
          weekly.push(make_pair(day, ans+costs[1]));
          month.push(make_pair(day,ans+costs[2]));
          ans=min(ans+costs[0],min(month.front().second,weekly.front().second));
        }
        return ans;
    }
};