class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n  = obstacles.size()-1;
        vector<int>next(4,INT_MAX);
        vector<int>curr(4,INT_MAX);
        next[0]=0;
        next[1]=0;
        next[3]=0;
        next[2]=0;
        for(int curr_pos =n-1;curr_pos>=0;curr_pos--)
        {
            for(int curr_lane=1;curr_lane<=3;curr_lane++)
            {
                if(obstacles[curr_pos+1]!=curr_lane)
                {
                    curr[curr_lane]=next[curr_lane];
                }
                else
                {
                    int ans=INT_MAX;
                    for(int i =1;i<=3;i++)
                    {
                        if(curr_lane!=i&&obstacles[curr_pos]!=i)
                        {
                            ans=min(ans,1+next[i]);
                        }
                    }
                    curr[curr_lane]=ans;
                }
            }
            next=curr;
        }
        return min(next[2],min(1+next[1],1+next[3]));
    }
};