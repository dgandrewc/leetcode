class Solution {
public:
    string longestPalindrome(string s) {
        string ans="";
        if(s.size()!=0)
            ans.append(1, s[0]);

        for(int i=0; i<s.size(); i++)
        {
            int l, r;
            l=r=i;
            while(l>=0 && r<s.size() && s[l]==s[r])
            {
                if(ans.size()<r-l+1)
                    ans=s.substr(l, r-l+1);
                l--;
                r++;
            }
            
            l=i;
            r=i+1;
            while(l>=0 && r<s.size() && s[l]==s[r])
            {
                if(ans.size()<r-l+1)
                    ans=s.substr(l, r-l+1);
                l--;
                r++;
            }
        }
        return ans;
    }
};