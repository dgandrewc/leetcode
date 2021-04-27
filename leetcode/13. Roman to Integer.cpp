class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m;
        int ans=0;
        vector<char> it={'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        
        m.insert({'I', 1});
        m.insert({'V', 5});
        m.insert({'X', 10});
        m.insert({'L', 50});
        m.insert({'C', 100});
        m.insert({'D', 500});
        m.insert({'M', 1000});
        
        for(int i=0; i<it.size(); i++)
        {
            for(int j=0; j<s.size(); j++)
            {
                if(s[j]==it[i])
                {
                    ans+=m[s[j]];
                    s[j]='A';
                    for(int k=j-1; k>=0; k--)
                    {
                        if(s[k]!='A')
                        {
                            ans-=m[s[k]];
                            s[k]='A';
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};