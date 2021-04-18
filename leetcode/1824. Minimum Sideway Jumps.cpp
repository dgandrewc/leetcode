class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int state=2;
        int ans=0;
        
        for(int i=0; i<obstacles.size(); i++)
        {
            if(obstacles[i+1]==state)
            {
                ans++;
                int j;
                if(obstacles[i]==0)
                {
                    for(j=i+1; j<obstacles.size() && (obstacles[j]==state || obstacles[j]==0); j++);
                    if(j==obstacles.size())
                        break;
                }
                else
                    j=i;
                
                if(obstacles[j]==1 && state==2)
                    state=3;
                else if(obstacles[j]==1 && state==3)
                    state=2;
                else if(obstacles[j]==2 && state==1)
                    state=3;
                else if(obstacles[j]==2 && state==3)
                    state=1;
                else if(obstacles[j]==3 && state==1)
                    state=2;
                else if(obstacles[j]==3 && state==2)
                    state=1;
            }
        }
        return ans;
    }
};