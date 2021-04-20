class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> v(numRows, vector<char>(1000, '-'));
        
        int flag=0;
        int x=0, y=0;
        string ans="";
        
        if(numRows==1)
            return s;
        
        for(int i=0; i<s.size(); i++)
        {
            if(flag==0)
            {
                v[x][y]=s[i];
                x++;
                if(x>=numRows)
                {
                    x-=2;
                    y++;
                    flag=1;
                }
            }
            else if(flag==1)
            {
                v[x][y]=s[i];
                x--;
                y++;
                if(x<0)
                {
                    x+=2;
                    y--;
                    flag=0;
                }
            }
        }
        for(int i=0; i<numRows; i++)
            for(int j=0; j<y+1; j++)
                if(v[i][j]!='-')
                    ans.append(1, v[i][j]);
        return ans;
    }
};