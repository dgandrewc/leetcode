class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="")
            return 0;
        
        string str="";
        int ans=1;
        
        for(int i=0; i<s.size(); i++)
        {
            int f=str.find(s[i]);
            if(f!=string::npos)
                str=str.substr(f+1);
            
            str+=s[i];
            ans=max(ans, int(str.length()));
        }
        return ans;
    }
};